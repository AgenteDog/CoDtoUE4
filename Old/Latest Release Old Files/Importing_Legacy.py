import unreal_engine as ue
from unreal_engine.classes import Actor, Character, PyFbxFactory
from unreal_engine.classes import TextureFactory, Material, StaticMesh
import glob, os
import json
from unreal_engine.structs import StaticMaterial, MeshUVChannelInfo

mesh_class = ue.find_class('StaticMesh')
material_class = ue.find_class('Material')
texture_class = ue.find_class('Texture2D')
material_instance_class = ue.find_class('MaterialInstanceConstant')

xmodels = r"E:\Drone\xmodels"
import_loc = '/Game/CoD/'
json_xmodels = r"E:\Drone\mp_drone\mp_drone_xmodels.json"

with open(json_xmodels, 'r') as file:
    entities = json.load(file)

props = []
textures = []
normal_textures = []
specular_textures = []
for info in entities:
    if not info.get('Name'):
        continue
    prop = {}
    prop['Prop'] = info['Name']
    if prop not in props:
        try:
            ue.load_object(mesh_class, import_loc + 'xmodels/' + info['Name'] + '.' + info['Name'])
        except:
            fbx_factory = PyFbxFactory()
            # build the path for the fbx file
            assets_dir = os.path.join(os.path.expanduser(xmodels), info['Name'])
            obj = os.path.join(assets_dir, info['Name'] + '_LOD0.obj')
            # configure the factory
            fbx_factory.ImportUI.bCreatePhysicsAsset = False
            fbx_factory.ImportUI.bImportMaterials = False
            fbx_factory.ImportUI.bImportTextures = False
            fbx_factory.ImportUI.bImportAnimations = False
            fbx_factory.ImportUI.StaticMeshImportData.bCombineMeshes = True
            fbx_factory.ImportUI.SkeletalMeshImportData.ImportUniformScale = 1;
            # import the mesh
            mesh = fbx_factory.factory_import_object(obj, import_loc + 'xmodels')
            ue.rename_asset(import_loc + 'xmodels/' + info['Name'] + '_LOD0' + '.' + info['Name'] + '_LOD0', info['Name'])
            props.append(prop)
    else:
        continue
for texture_info in entities:
    if not texture_info.get('Name'):
        continue

    #This part is a complete mess, sorry.
    os.chdir(xmodels + '\\' + texture_info['Name'])
    for image_info_file_name in glob.glob("*_images.txt"):
        with open(image_info_file_name,"r") as image_info_file:
            for image_info in image_info_file:
                texture = {}
                normal_texture = {}
                specular_texture = {}
                image_info = image_info.strip()
                if image_info.startswith('colorMap,'):
                    color_map_nameonly = image_info[image_info.rfind(',') + 1:]
                    texture['Texture'] = color_map_nameonly
                    if texture not in textures:
                        texture_factory = TextureFactory()
                        texture_factory.OverwriteYesOrNoToAllState = 2
                        color_map = image_info[image_info.rfind(',') + 1:] + '.tga'
                        color_tga = os.path.join(xmodels, '_images/' + color_map)
                        try:
                            color_map_nameonly = color_map_nameonly.replace('~', '_')
                            color_map_nameonly = color_map_nameonly.replace('#', '_')
                            color_map_nameonly = color_map_nameonly.replace('$', '_')
                            color_map_nameonly = color_map_nameonly.replace('&', '_')
                            ue.load_object(texture_class, import_loc + 'textures/' + color_map_nameonly + '.' + color_map_nameonly)
                        except:
                            texture_import_color_tga= texture_factory.factory_import_object(color_tga, import_loc + 'textures')
                        textures.append(texture)
                if image_info.startswith('normalMap,'):
                    normal_line = image_info[image_info.rfind(',') + 1:]
                    if normal_line != '$identitynormalmap':
                        if normal_line != None:
                            normal_map_nameonly = normal_line
                            normal_texture['Texture'] = normal_map_nameonly
                            if normal_texture not in normal_textures:
                                texture_factory = TextureFactory()
                                texture_factory.OverwriteYesOrNoToAllState = 2
                                normal_map = normal_line + '.tga'
                                normal_tga = os.path.join(xmodels, '_images/' + normal_map)
                                try:
                                    normal_map_nameonly = normal_map_nameonly.replace('~', '_')
                                    normal_map_nameonly = normal_map_nameonly.replace('#', '_')
                                    normal_map_nameonly = normal_map_nameonly.replace('$', '_')
                                    normal_map_nameonly = normal_map_nameonly.replace('&', '_')
                                    ue.load_object(texture_class, import_loc + 'textures/' + normal_map_nameonly + '.' + normal_map_nameonly)
                                except:
                                    texture_import_normal_tga = texture_factory.factory_import_object(normal_tga, import_loc + 'textures')
                                normal_textures.append(normal_texture)
                if image_info.startswith('unk_semantic_0x34ECCCB3,'):
                    specular_line = image_info[image_info.rfind(',') + 1:]
                    specular_map_nameonly = specular_line
                    specular_texture['Texture'] = specular_map_nameonly
                    if specular_texture not in specular_textures:
                        texture_factory = TextureFactory()
                        texture_factory.OverwriteYesOrNoToAllState = 2
                        specular_map = specular_line + '.tga'
                        specular_tga = os.path.join(xmodels, '_images/' + specular_map)
                        try:
                            specular_map_nameonly = specular_map_nameonly.replace('~', '_')
                            specular_map_nameonly = specular_map_nameonly.replace('#', '_')
                            specular_map_nameonly = specular_map_nameonly.replace('$', '_')
                            specular_map_nameonly = specular_map_nameonly.replace('&', '_')
                            ue.load_object(texture_class, import_loc + 'textures/' + specular_map_nameonly + '.' + specular_map_nameonly)
                        except:
                            texture_import_specular_tga = texture_factory.factory_import_object(specular_tga, import_loc + 'textures')
                        specular_textures.append(specular_texture)


#Lists in wich the parsed info will be stored
model_names = []
slot_names = []
diffuse_names = []
normal_names = []
specular_names = []
emmisive_names = []

#Start the loop
for texture_info in entities:
    if not texture_info.get('Name'):
        continue

    #Parse model names in order to avoid the same model being parsed twice.
    model_name = {}
    model_name['Name'] = texture_info['Name']

    if model_name not in model_names:

        #Set location in wich to search files and then search
        os.chdir(xmodels + '\\' + texture_info['Name'])
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
                    emmisive_name = {}
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

            if normal_found:
                normal_name['Name'] = normal_texture
                normal_names.append(normal_name)

            if specular_found:
                specular_name['Name'] = specular_texture
                specular_names.append(specular_name)

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
                 ue.load_object(material_instance_class, import_loc + 'materials/' + name + '.' + name)
            except:
                if not albedo == 'Default':
                    texture = ue.load_object(texture_class, import_loc + 'textures/' + albedo + '.' + albedo)
                    if texture.texture_has_alpha_channel() == True:
                        #master_material = ue.load_object(material_class, '/Game/MasterMat_Opacity.MasterMat_Opacity')
                        master_material = ue.load_object(material_class, '/Game/MasterMat.MasterMat')
                    else:
                        master_material = ue.load_object(material_class, '/Game/MasterMat.MasterMat')
                else:
                    master_material = ue.load_object(material_class, '/Game/MasterMat.MasterMat')
                #Select and create master material
                material_instance = ue.create_material_instance(master_material, import_loc + 'materials/', name)

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
            asset = ue.load_object(mesh_class, import_loc + 'xmodels/' + model_name['Name'] + '.' + model_name['Name'])
            for index, material in enumerate(asset.StaticMaterials):
                if material.MaterialSlotName == name:
                    component = ue.load_object(mesh_class, import_loc + 'xmodels/' + model_name['Name'] + '.' + model_name['Name'])
                    material = ue.load_object(material_instance_class, import_loc + 'materials/' + name + '.' + name)
                    component.set_material(index, material);

        #Clear the list and append model.
        slot_names.clear()
        normal_names.clear()
        diffuse_names.clear()
        specular_names.clear()
    model_names.append(model_name)
