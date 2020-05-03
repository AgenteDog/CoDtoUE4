#Settings!
geo_map = "mp_village"
geo_directory = r"E:\Tutorial\Standoff"
xmodels_path = r"/Game/CoD/"
extension = ".tga"

#Optional Settings!
opacity = ("grass", "foliage", "glass", "paper", "tree", "ivy")
import_geometry = True
individual_geometry_objects = False

#Some other stuff (I recommend not touching these)
missing_texture = "missing.tga"
error_object= "error.fbx"

#Script
import unreal_engine as ue
from unreal_engine.classes import Actor, Character, PyFbxFactory, TextureFactory, Material, StaticMesh
from unreal_engine.structs import StaticMaterial, MeshUVChannelInfo
import glob, os, json

#Basic/Necessary things.
mesh_class = ue.find_class("StaticMesh")
material_class = ue.find_class("Material")
texture_class = ue.find_class("Texture2D")
material_instance_class = ue.find_class("MaterialInstanceConstant")


geo_folder = geo_directory + "\\" + geo_map + "\\" # This is the folder where the map geometry is stored. Its basically the directory + the map name.
geo_mtl_file = geo_directory + "\\" + geo_map + "\\" + geo_map + ".mtl" # This is the folder where the mtl of the map geometry is stored.


xmodels_directory = geo_directory + r"\xmodels" # This is the xmodels directory.
xmodels_json = geo_directory + "\\" + geo_map + "\\" + geo_map + "_xmodels.json" #This is where the json file is stored.

missing_texture_name = missing_texture.rsplit(".", 1)
error_object_name = error_object.rsplit(".", 1)

# Functions
#Fix text so that it is usable on ue4
def clean(text):
    new_text = text.replace('~', '_').replace('#', '_').replace('$', '_').replace('&', '_')
    return new_text

#Import textures
def import_texture(texture_map):

    texture_clean = clean(texture_map)

    try:
        #Check if textures exists
        ue.load_object(texture_class, xmodels_path + "textures/" + texture_clean + "." + texture_clean)

    except:
        #If it does not exist, import it. if the texture is also not avialable for import then import the missing texture
        try:
            texture_factory = TextureFactory()
            texture_factory.OverwriteYesOrNoToAllState = 2
            texture_tga = os.path.join(xmodels_directory, '_images/' + texture_map + extension)
            texture_factory.factory_import_object(texture_tga, xmodels_path + 'textures')

        except:
            texture_factory = TextureFactory()
            texture_factory.OverwriteYesOrNoToAllState = 2
            texture_tga = os.path.join(xmodels_directory, '_images/' + missing_texture)
            texture_factory.factory_import_object(texture_tga, xmodels_path + 'textures')
            ue.rename_asset(xmodels_path + "textures/" + missing_texture_name[0] + "." + missing_texture_name[0], texture_clean)

with open(xmodels_json, "r") as file:
    entities = json.load(file)


#All importing happens by steps. (First parsing, then props import, then textures and finally materials are aplied.)
#1. Parsing

props = [] #All props (including missig ones) will be added here.
props_clean = [] #Missing props will not be added here.

for model in entities:
    prop = {}
    prop_clean = {}
    prop["Name"] = str(model.get("Name"))

    #I want to check if a model is missing while parsing, if it is missing it does not get added to props_clean.
    if not os.path.isdir(xmodels_directory + "/" + prop["Name"]):
        prop["Name"] = prop["Name"] + "_missing"

    else:
        prop_clean["Name"] = prop["Name"]

    props_clean.append(prop_clean)

    #Append and keep going.
    if prop not in props:
        props.append(prop)

    else:
        continue

#2. Props Import
#First I check if the files end with _LOD0 or not by checking one of the props.

LOD0 = ""
if os.path.isfile(xmodels_directory + "/" + str(prop_clean["Name"]) + "/" + str(prop_clean["Name"]) + "_LOD0.obj"):
    LOD0 = "_LOD0"

unknown_prop_number = 0
#Start importing
for model in props:

    prop_name = model['Name']

    if model["Name"].endswith("_missing"):
        prop_name = model["Name"][:model['Name'].rfind("_missing")]

    if not prop_name == 'None':
        try:
            ue.load_object(mesh_class, xmodels_path + "xmodels/" + prop_name + "." + prop_name)

        except:
            fbx_factory = PyFbxFactory()

            # build the path for the fbx file
            if model["Name"].endswith("_missing"):
                assets_dir = os.path.join(os.path.expanduser(xmodels_directory), error_object_name[0])
                obj = os.path.join(assets_dir, error_object)

            else:
                assets_dir = os.path.join(os.path.expanduser(xmodels_directory), model["Name"])
                obj = os.path.join(assets_dir, model["Name"] + LOD0 + ".obj")

            # configure the factory
            fbx_factory.ImportUI.bCreatePhysicsAsset = False
            fbx_factory.ImportUI.bImportMaterials = False
            fbx_factory.ImportUI.bImportTextures = False
            fbx_factory.ImportUI.bImportAnimations = False
            fbx_factory.ImportUI.StaticMeshImportData.bCombineMeshes = True
            fbx_factory.ImportUI.SkeletalMeshImportData.ImportUniformScale = 1;

            # import the mesh
            mesh = fbx_factory.factory_import_object(obj, xmodels_path + "xmodels")

            if model["Name"].endswith("_missing"):
                ue.rename_asset(xmodels_path + "xmodels/" + error_object_name[0] + "." + error_object_name[0], prop_name)

            else:
                ue.rename_asset(xmodels_path + "xmodels/" + prop_name + LOD0 + "." + prop_name + LOD0, prop_name)

            props.append(prop)


#3. Materials
model_names = []
slot_names = []
diffuse_names = []
normal_names = []
specular_names = []

#Start the loop
for texture_info in entities:
    if not texture_info.get('Name'):
        continue

    #Parse model names in order to avoid the same model being parsed twice.
    model_name = {}
    model_name['Name'] = texture_info['Name']

    #Check if model exists.
    if not os.path.isdir(xmodels_directory + "/" + texture_info["Name"]):
        continue

    if model_name not in model_names:

        #Set location in wich to search files and then search
        os.chdir(xmodels_directory + '\\' + texture_info['Name'])
        for mtl_file in glob.glob("*.mtl"):

            #Set slot names and the name of the txt file to parse texture info from
            slot_name_raw = mtl_file[:mtl_file.rfind('.mtl')]
            images_file = slot_name_raw + '_images.txt'
            slot_name = {}
            slot_name['Name'] = slot_name_raw
            slot_names.append(slot_name)

            #Open the txt file
            with open(images_file, "r") as images_file_info:

                diffuse_found = False
                normal_found = False
                specular_found = False

                for texture_info in images_file_info:

                    #Set dicts and strip the lines
                    diffuse_name = {}
                    normal_name = {}
                    specular_name = {}
                    texture_info = texture_info.strip()

                    #Search for line that starts with "colorMap"
                    if texture_info.startswith("colorMap,"):
                        diffuse_found = True
                        diffuse_texture = texture_info[texture_info.rfind(',') + 1:]

                    #Search for line that starts with "normalMap"
                    if texture_info.startswith("normalMap,"):
                        normal_texture = texture_info[texture_info.rfind(',') + 1:]
                        if normal_texture != '$identitynormalmap':
                            normal_found = True

                    #Search for line that starts with "unk_semantic_0x34ECCCB3" (specular map)
                    if texture_info.startswith("unk_semantic_0x34ECCCB3,"):
                        specular_found = True
                        specular_texture = texture_info[texture_info.rfind(',') + 1:]

            #If line is found in the file:
            if diffuse_found:
                diffuse_name['Name'] = diffuse_texture
                diffuse_names.append(diffuse_name)

                import_texture(diffuse_texture)


            if normal_found:
                normal_name['Name'] = normal_texture
                normal_names.append(normal_name)

                import_texture(normal_texture)


            if specular_found:
                specular_name['Name'] = specular_texture
                specular_names.append(specular_name)

                import_texture(specular_texture)


            #If the line is not found in the file:
            if not diffuse_found:
                diffuse_name['Name'] = 'Default'
                diffuse_names.append(diffuse_name)

            if not normal_found:
                normal_name['Name'] = 'Default'
                normal_names.append(normal_name)

            if not specular_found:
                specular_name['Name'] = 'Default'
                specular_names.append(specular_name)

        #Start using the data
        for slot_name, albedo, normal, specular in zip(slot_names, diffuse_names, normal_names, specular_names):

            #Replace all "illegal characters" with a "_"
            name = clean(slot_name['Name'])
            albedo = clean(albedo['Name'])
            normal = clean(normal['Name'])
            specular = clean(specular_name['Name'])

            #Check if the albedo texture exists, if it does then decide if it has alpha channel or not
            try:
                 ue.load_object(material_instance_class, xmodels_path + 'materials/' + name + '.' + name)

            except:

                if not albedo == 'Default':
                    texture = ue.load_object(texture_class, xmodels_path + 'textures/' + albedo + '.' + albedo)

                    if any(item in name for item in (opacity)):
                        master_material = ue.load_object(material_class, '/Game/MasterMat_Opacity.MasterMat_Opacity')

                    else:
                        master_material = ue.load_object(material_class, '/Game/MasterMat.MasterMat')
                else:
                    master_material = ue.load_object(material_class, '/Game/MasterMat.MasterMat')

                #Select and create material
                material_instance = ue.create_material_instance(master_material, xmodels_path + 'materials/', name)

                #Assign the albedo texture to the instance if the texture exists
                if not albedo == 'Default':
                    material_instance.get_material_scalar_parameter('AlbedoTexture')
                    current_texture = ue.load_object(texture_class, '/Game/CoD/textures/' + albedo + '.' + albedo )
                    material_instance.set_material_texture_parameter('AlbedoTexture', current_texture)

                #Assign the normal texture to the instance if the texture exists
                if not normal == 'Default':
                    material_instance.get_material_scalar_parameter('NormalTexture')
                    current_texture = ue.load_object(texture_class, '/Game/CoD/textures/' + normal + '.' + normal)
                    material_instance.set_material_texture_parameter('NormalTexture', current_texture)

                #Assign the specular texture to the instance if the texture exists
                if not specular == 'Default':
                    material_instance.get_material_scalar_parameter('SpecularTexture')
                    current_texture = ue.load_object(texture_class, '/Game/CoD/textures/' + specular + '.' + specular)
                    material_instance.set_material_texture_parameter('SpecularTexture', current_texture)

                #Assign the material to the asset
            asset = ue.load_object(mesh_class, xmodels_path + 'xmodels/' + model_name['Name'] + '.' + model_name['Name'])
            for index, material in enumerate(asset.StaticMaterials):
                if material.MaterialSlotName == name:
                    component = ue.load_object(mesh_class, xmodels_path + 'xmodels/' + model_name['Name'] + '.' + model_name['Name'])
                    material = ue.load_object(material_instance_class, xmodels_path + 'materials/' + name + '.' + name)
                    component.set_material(index, material);

        #Clear the list and append model.
        slot_names.clear()
        normal_names.clear()
        diffuse_names.clear()
        specular_names.clear()
    model_names.append(model_name)


#4. Map Geometry

if import_geometry:

    with open(f"{geo_folder}{geo_map}_matdata.json", "r") as file:
        geo_matfile = json.load(file)

    #If the perfect geometry physics setting is on
    if individual_geometry_objects:
        models = []

        with open(f"{geo_folder}{geo_map}.obj", 'r') as geo:
            new_geometry = open(f"{geo_folder}p_{geo_map}.obj", "a")

            for _line in geo.readlines():

                line = _line.strip()

                if line.startswith("g "):

                    model_name = line[line.rfind(" ") + 1:]

                    model_info = {}
                    model_info['Number'] = 1
                    model_info['Model'] = model_name

                    for model in models:
                        if model_name == model['Model']:
                            model_info['Number'] = model['Number']
                            number_temp = model['Number'] + 1

                    if model_info not in models:
                        models.append(model_info)

                    elif model_info in models:
                        models.remove(model_info)
                        model_info['Number'] = number_temp
                        models.append(model_info)

                    new_geometry.write(f"g {model_info['Model']}{model_info['Number']}\n")

                else:
                    new_geometry.write(line + "\n")

            new_geometry.close()
            geo_map = f"p_{geo_map}"

    #Lets import the map geometry
    fbx_factory = PyFbxFactory()
    assets_dir = os.path.join(os.path.expanduser(geo_folder))
    obj = os.path.join(assets_dir, geo_map + ".obj")

    # configure the factory
    fbx_factory.ImportUI.bCreatePhysicsAsset = False
    fbx_factory.ImportUI.bImportMaterials = False
    fbx_factory.ImportUI.bImportTextures = False
    fbx_factory.ImportUI.bImportAnimations = False
    fbx_factory.ImportUI.StaticMeshImportData.bCombineMeshes = False
    fbx_factory.ImportUI.SkeletalMeshImportData.ImportUniformScale = 1;

    mesh = fbx_factory.factory_import_object(obj, xmodels_path + "MapGeo")

    if individual_geometry_objects:
        os.remove(f"{geo_folder}{geo_map}.obj")

    #Import textures
    for textures in geo_matfile['Materials'].values():
        for texture in textures.values():
            import_texture(texture)

    #Now its time to create all the materials
    for slot, texture in geo_matfile['Materials'].items():

        #Replace all "illegal characters" with a "_"
        slot_name = clean(slot)

        #Select master
        if any(item in slot_name for item in (opacity)):
            master_material = ue.load_object(material_class, '/Game/MasterMat_Opacity.MasterMat_Opacity')

        else:
            master_material = ue.load_object(material_class, '/Game/MasterMat.MasterMat')

        #create instance if it does not exist
        try:
            ue.load_object(material_instance_class, xmodels_path + 'materials/' + f"{slot_name}.{slot_name}")
        except:

                material_instance = ue.create_material_instance(master_material, xmodels_path + 'materials/', slot_name)

                #Assign albedo texture
                try:

                    albedo = clean(texture['Color Map'])

                    material_instance.get_material_scalar_parameter('AlbedoTexture')
                    current_texture = ue.load_object(texture_class, '/Game/CoD/textures/' + albedo + '.' + albedo )
                    material_instance.set_material_texture_parameter('AlbedoTexture', current_texture)

                except:
                    pass
                    #Dont worry if it gets here, it just means that the material has no Albedo

                #Assign normal texture
                try:

                    normal = clean(texture['Normal Map'])

                    if not normal == '$identitynormalmap':
                        material_instance.get_material_scalar_parameter('NormalTexture')
                        current_texture = ue.load_object(texture_class, '/Game/CoD/textures/' + normal + '.' + normal)
                        material_instance.set_material_texture_parameter('NormalTexture', current_texture)

                except:
                    pass
                    #Dont worry if it gets here, it just means that the material has no Normal

                #Assign Specular Texture
                try:

                    specular = clean(specular['Specular Map'])

                    material_instance.get_material_scalar_parameter('SpecularTexture')
                    current_texture = ue.load_object(texture_class, '/Game/CoD/textures/' + specular + '.' + specular)
                    material_instance.set_material_texture_parameter('SpecularTexture', current_texture)

                except:
                    pass
                    #Dont worry if it gets here, it just means that the material has no Specular

        if not individual_geometry_objects:

            #Assign the materials
            model_name = f"{geo_map}_{clean(slot)}"

            asset = ue.load_object(mesh_class, xmodels_path + 'MapGeo/' + model_name + '.' + model_name)

            for index, material in enumerate(asset.StaticMaterials):
                if clean(slot) in material.MaterialSlotName :

                    component = ue.load_object(mesh_class, xmodels_path + 'MapGeo/' + model_name + '.' + model_name)
                    material = ue.load_object(material_instance_class, xmodels_path + 'materials/' + slot_name + '.' + slot_name)
                    component.set_material(index, material);


    if individual_geometry_objects:
        for material_info in models:
            for model_number in range(1, material_info['Number'] + 1):

                #Assign the materials

                info_model = clean(material_info['Model'])

                model_name = f"{geo_map}_{info_model}{model_number}"

                asset = ue.load_object(mesh_class, xmodels_path + 'MapGeo/' + model_name + '.' + model_name)

                for index, material in enumerate(asset.StaticMaterials):
                    if info_model in material.MaterialSlotName:

                        component = ue.load_object(mesh_class, xmodels_path + 'MapGeo/' + model_name + '.' + model_name)
                        material = ue.load_object(material_instance_class, xmodels_path + 'materials/' + info_model + '.' + info_model)
                        component.set_material(index, material);

print("Done!!")
