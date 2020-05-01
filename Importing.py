import unreal_engine as ue
from unreal_engine.classes import Actor, Character, PyFbxFactory, TextureFactory, Material, StaticMesh
from unreal_engine.structs import StaticMaterial, MeshUVChannelInfo
import glob, os, json

#Basic/Necessary things.
mesh_class = ue.find_class("StaticMesh")
material_class = ue.find_class("Material")
texture_class = ue.find_class("Texture2D")
material_instance_class = ue.find_class("MaterialInstanceConstant")

xmodels_directory = r"E:\Drone\xmodels"
xmodels_path = r"/Game/CoD/"
xmodels_json = r"E:\Drone\mp_drone\mp_drone_xmodels.json"

geo_directory = r"E:\Drone\mp_drone"
geo_mtl_file = geo_directory + r"\mp_drone.mtl"

extension = ".tga"

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

#Start importing
for model in props:
    try:
        ue.load_object(mesh_class, xmodels_path + "xmodels/" + model["Name"] + "." + model["Name"])

    except:
        fbx_factory = PyFbxFactory()

        # build the path for the fbx file
        if model["Name"].endswith("_missing"):
            assets_dir = os.path.join(os.path.expanduser(xmodels_directory), "error")
            obj = os.path.join(assets_dir, "error" + ".fbx")

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
            ue.rename_asset(xmodels_path + "xmodels/" + "error" + "." + "error",model["Name"])

        else:
            ue.rename_asset(xmodels_path + "xmodels/" + model["Name"] + LOD0 + "." + model["Name"] + LOD0, model["Name"])

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

                texture_factory = TextureFactory()
                texture_factory.OverwriteYesOrNoToAllState = 2
                texture_tga = os.path.join(xmodels_directory, '_images/' + diffuse_texture + extension)
                texture_factory.factory_import_object(texture_tga, xmodels_path + 'textures')

            if normal_found:
                normal_name['Name'] = normal_texture
                normal_names.append(normal_name)

                texture_factory = TextureFactory()
                texture_factory.OverwriteYesOrNoToAllState = 2
                texture_tga = os.path.join(xmodels_directory, '_images/' + normal_texture + extension)
                texture_factory.factory_import_object(texture_tga, xmodels_path + 'textures')

            if specular_found:
                specular_name['Name'] = specular_texture
                specular_names.append(specular_name)

                texture_factory = TextureFactory()
                texture_factory.OverwriteYesOrNoToAllState = 2
                texture_tga = os.path.join(xmodels_directory, '_images/' + specular_texture + extension)
                texture_factory.factory_import_object(texture_tga, xmodels_path + 'textures')

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
            name = slot_name['Name'].replace('~', '_')
            name = name[name.rfind('-') + 1:]
            name = name.replace('#', '_')
            name = name.replace('$', '_')
            name = name.replace('&', '_')
            albedo = albedo['Name'].replace('~', '_')
            albedo = albedo.replace('#', '_')
            albedo = albedo.replace('$', '_')
            albedo = albedo.replace('&', '_')
            normal = normal['Name']
            specular = specular_name['Name'].replace('~', '_')
            specular = specular.replace('#', '_')
            specular = specular.replace('$', '_')
            specular = specular.replace('&', '_')

            #Check if the albedo texture exists, if it does then decide if it has alpha channel or not
            try:
                 ue.load_object(material_instance_class, xmodels_path + 'materials/' + name + '.' + name)

            except:
                if not albedo == 'Default':
                    texture = ue.load_object(texture_class, xmodels_path + 'textures/' + albedo + '.' + albedo)
                    if texture.texture_has_alpha_channel() == True:
                        #master_material = ue.load_object(material_class, '/Game/MasterMat_Opacity.MasterMat_Opacity')
                        master_material = ue.load_object(material_class, '/Game/MasterMat.MasterMat')
                    else:
                        master_material = ue.load_object(material_class, '/Game/MasterMat.MasterMat')
                else:
                    master_material = ue.load_object(material_class, '/Game/MasterMat.MasterMat')
                #Select and create master material
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
#First parsing all the slots, textures, etc.

geo_slots = []
geo_albedos = []

with open(geo_mtl_file, 'r') as file:

    for line in file.readlines():
        geo_slot = {}
        geo_albedo = {}

        _line = line.strip()

        if _line.startswith("newmtl"):
            geo_slot_name = _line[_line.rfind(" ") + 1:]

            geo_slot_name = geo_slot_name.replace('~', '_')
            geo_slot_name = geo_slot_name.replace('#', '_')
            geo_slot_name = geo_slot_name.replace('$', '_')
            geo_slot_name = geo_slot_name.replace('&', '_')

            geo_slot['Name'] = geo_slot_name
            geo_slots.append(geo_slot)

        elif _line.startswith("map_Kd"):
            geo_albedo_name = _line[_line.rfind(r"\\") + 2:]
            geo_albedo_name = geo_albedo_name[:geo_albedo_name.rfind(".png")]

            texture_factory = TextureFactory()
            texture_factory.OverwriteYesOrNoToAllState = 2
            texture_tga = os.path.join(xmodels_directory, '_images/' + geo_albedo_name + extension)
            texture_factory.factory_import_object(texture_tga, xmodels_path + 'textures')

            geo_albedo_name = geo_albedo_name.replace('~', '_')
            geo_albedo_name = geo_albedo_name.replace('#', '_')
            geo_albedo_name = geo_albedo_name.replace('$', '_')
            geo_albedo_name = geo_albedo_name.replace('&', '_')

            geo_albedo['Name'] = geo_albedo_name
            geo_albedos.append(geo_albedo)


#Now lets import the map geometry
try:
    ue.load_object(mesh_class, xmodels_path + "MapGeo/" + "mp_drone" + "." + "mp_drone")

except:
    fbx_factory = PyFbxFactory()
    assets_dir = os.path.join(os.path.expanduser(geo_directory))
    obj = os.path.join(assets_dir, "mp_drone" + ".obj")

    # configure the factory
    fbx_factory.ImportUI.bCreatePhysicsAsset = False
    fbx_factory.ImportUI.bImportMaterials = False
    fbx_factory.ImportUI.bImportTextures = False
    fbx_factory.ImportUI.bImportAnimations = False
    fbx_factory.ImportUI.StaticMeshImportData.bCombineMeshes = True
    fbx_factory.ImportUI.SkeletalMeshImportData.ImportUniformScale = 1;

    # import the mesh
    mesh = fbx_factory.factory_import_object(obj, xmodels_path + "MapGeo")


#Im not sure if this works! That is why its a comment! Feel free to edit it or whatever if you want
#Now its time to create all the materials
'''
for slot, albedo in zip(geo_slots, geo_albedos):
    print("lets go boi")
    #Select master and create instance
    master_material = ue.load_object(material_class, '/Game/MasterMat.MasterMat')
    material_instance = ue.create_material_instance(master_material, xmodels_path + 'materials/', slot['Name'])

    #Assign albedo texture
    material_instance.get_material_scalar_parameter('AlbedoTexture')
    current_texture = ue.load_object(texture_class, '/Game/CoD/textures/' + albedo['Name'] + '.' + albedo['Name'] )
    material_instance.set_material_texture_parameter('AlbedoTexture', current_texture)

    #Assign the materials
    asset = ue.load_object(mesh_class, xmodels_path + 'MapGeo/' + "mp_drone" + '.' + "mp_drone")

    for index, material in enumerate(asset.StaticMaterials):
        if material.MaterialSlotName == slot['Name'] + "Mat":
            component = ue.load_object(mesh_class, xmodels_path + 'MapGeo/' + "mp_drone" + '.' + "mp_drone")
            material = ue.load_object(material_instance_class, xmodels_path + 'materials/' + slot['Name'] + '.' + slot['Name'])
            component.set_material(index, material);
'''
