from necessary import *

class props:

    #Import all props
    def _import(map_name, map_folder, import_folder, greyhound_folder, assets_folder, global_opacity, opacity_items):

        with open(f"{map_folder}\\{map_name}_xmodels.json", "r") as file:
            entities = json.load(file)


        props = []
        for prop in entities:
            if 'Name' in prop and prop['Name'] not in props:
                    props.append(prop['Name'])


        model_found = False
        for model in props:

            #Import models
            model_clean = clean(model)

            try:
                ue.load_object(mesh_class, f"{import_folder}xmodels/{model_clean}.{model_clean}")

            except:

                for file in files_list(greyhound_folder):
                    if file['Name'] == model and file['Type'] == "obj":

                        model_found = True
                        model_full_directory = file['Full Directory']
                        prop_original_name = file['Original Name']

                        fbx_factory = PyFbxFactory()
                        obj = model_full_directory

                        # configure the factory
                        fbx_factory.ImportUI.bCreatePhysicsAsset = False
                        fbx_factory.ImportUI.bImportMaterials = False
                        fbx_factory.ImportUI.bImportTextures = False
                        fbx_factory.ImportUI.bImportAnimations = False
                        fbx_factory.ImportUI.StaticMeshImportData.bCombineMeshes = True
                        fbx_factory.ImportUI.SkeletalMeshImportData.ImportUniformScale = 1;

                        mesh = fbx_factory.factory_import_object(obj, f"{import_folder}xmodels")
                        ue.rename_asset(f"{import_folder}xmodels/{clean(prop_original_name)}.{clean(prop_original_name)}", model_clean)

                if not model_found:
                    ue.duplicate_asset(f"{assets_folder}error.error", f"{import_folder}xmodels/{model_clean}", model_clean)


        for model in props:

            model_clean = clean(model)
            all_material_info = []

            #Look for file, get slot name from mtl file and open _images file in order to get all the material info needed
            for file in files_list(greyhound_folder):
                if file['Name'] == model:
                    for textures_file in files_list(file['Directory']):

                        if textures_file['Raw Name'].endswith(".mtl"):

                            material_info = {}

                            material_info['Slot'] = textures_file['Original Name']

                            #Set default values
                            material_info['Albedo'] = "Default"
                            material_info['Normal'] = "Default"
                            material_info['Specular'] = "Default"

                            #Add real values if texture is found
                            _imagesLocation = f"{textures_file['Directory']}/{textures_file['Original Name']}_images.txt"
                            if os.path.isfile(_imagesLocation):
                                with open(_imagesLocation) as images_info:

                                    for _line in images_info:

                                        line = _line.strip()

                                        if line.startswith("colorMap,"):

                                            texture_name = line[line.rfind(',') + 1:]
                                            material_info['Albedo'] = texture_name

                                            import_texture(texture_name, import_folder, greyhound_folder, assets_folder)

                                        if line.startswith("normalMap,"):

                                            texture_name = line[line.rfind(',') + 1:]
                                            material_info['Normal'] = texture_name

                                            import_texture(texture_name, import_folder, greyhound_folder, assets_folder)

                                        if line.startswith("unk_semantic_0x34ECCCB3,"):

                                            texture_name = line[line.rfind(',') + 1:]
                                            material_info['Specular'] = texture_name

                                            import_texture(texture_name, import_folder, greyhound_folder, assets_folder)

                            all_material_info.append(material_info)


            #Create and assign materials
            for material_value in all_material_info:

                #Replace all "illegal characters" with a "_"
                name = clean(material_value['Slot'])
                slot = name
                albedo = clean(material_value['Albedo'])
                normal = clean(material_value['Normal'])
                specular = clean(material_value['Specular'])

                try:
                    check_material_existance(name, import_folder, assets_folder, global_opacity, opacity_items, model_clean)

                except:

                    #Select master and create instance
                    master_material = select_master_material(global_opacity, opacity_items, name, import_folder, assets_folder)
                    material_instance = ue.create_material_instance(master_material, f"{import_folder}materials/", slot)

                    #Start assigning values
                    if not albedo == 'Default':

                        texture_name = albedo

                        current_texture = ue.load_object(texture_class, f"{import_folder}textures/{texture_name}.{texture_name}" )
                        material_instance.set_material_texture_parameter('AlbedoTexture', current_texture)

                    if not normal == 'Default':

                        texture_name = normal

                        current_texture = ue.load_object(texture_class, f"{import_folder}textures/{texture_name}.{texture_name}" )
                        material_instance.set_material_texture_parameter('NormalTexture', current_texture)

                    if not specular == 'Default':

                        texture_name = specular
                        current_texture = ue.load_object(texture_class, f"{import_folder}textures/{texture_name}.{texture_name}" )

                        material_instance.set_material_static_switch_parameter('Specular', True)
                        material_instance.set_material_texture_parameter('SpecularTexture', current_texture)

                #Actually start assigning the material to the model
                asset = ue.load_object(mesh_class, f"{import_folder}xmodels/{model_clean}.{model_clean}")
                selected_material = ue.load_object(material_instance_class, f"{import_folder}materials/{slot}.{slot}")

                for index, material in enumerate(asset.StaticMaterials):
                    if slot in material.MaterialSlotName:
                        if material.MaterialInterface != selected_material:
                            asset.set_material(index, selected_material)

            all_material_info.clear()
            material_info.clear()



    #Re-assign parent of instances, useful if someone goes from global_opacity to not having global_opacity (and the opossite)
    def re_parent_materials(map_name, map_folder, import_folder, greyhound_folder, assets_folder, global_opacity, opacity_items):

        #Get all necessary info
        with open(f"{map_folder}\\{map_name}_xmodels.json", "r") as file:
            entities = json.load(file)


        props = []
        for prop in entities:
            if 'Name' in prop and prop['Name'] not in props:
                    props.append(prop['Name'])

        #Get all prop material names and change the parent material if needed
        for model in props:
            for file in files_list(greyhound_folder):
                if file['Name'] == model:
                    for textures_file in files_list(file['Directory']):
                        if textures_file['Raw Name'].endswith(".mtl"):

                            material_name = clean(textures_file['Original Name'])
                            check_material_existance(material_name, import_folder, assets_folder, global_opacity, opacity_items, model)




    #Place props
    def place(map_name, map_folder, import_folder):

        #Get (raw) necessary info
        with open(f"{map_folder}\\{map_name}_xmodels.json", "r") as file:
            entities = json.load(file)

        cube_placeholder = ue.load_object(StaticMesh, '/Engine/BasicShapes/Cube.Cube')

        #Create cube to hold all props
        props_cube = ue.get_editor_world().actor_spawn(StaticMeshActor, FVector(0, 0, 0), FRotator(0, 0, 0))
        props_cube.StaticMeshComponent.StaticMesh = cube_placeholder
        props_cube.set_actor_label('Props')


        #Start the placing process
        actors_info = []

        for actor in entities:

            #If the actor meets all this requirements then it proceeds to place it.
            actor_requirements = ['Name', 'RotX', 'RotY', 'RotZ', 'PosX', 'PosY', 'PosZ', 'Scale']

            if all(item in actor for item in (actor_requirements)):

                #Get all the info required
                name = clean(actor['Name'])

                RotX = (float(actor['RotX'])) * math.pi/180
                RotY = (float(actor['RotY'])) * math.pi/180
                RotZ = (float(actor['RotZ'])) * math.pi/180

                RotX = RotX * 180/math.pi
                RotY = RotY * 180/math.pi
                RotZ = RotZ * 180/math.pi

                PosX = float(actor['PosX'])
                PosY = float(actor['PosY'])
                PosZ = float(actor['PosZ'])

                Scale = float(actor['Scale']) * 0.3937


                #Classify the actor and it's number (this is 2 stop an actor placed twice from having the same)

                current_number = None
                actor_info = {}

                actor_info['Number'] = 1
                actor_info['Model'] = name

                for model in actors_info:
                    if name == model['Model']:
                        actor_info['Number'] = model['Number']
                        current_number = model['Number'] + 1

                if actor_info not in actors_info:
                    actors_info.append(actor_info)

                elif actor_info in actors_info:

                    actors_info.remove(actor_info)
                    actor_info['Number'] = current_number
                    actors_info.append(actor_info)

                #Place the actor
                try:

                    asset = ue.load_object(StaticMesh, f"{import_folder}xmodels/{name}.{name}")

                    spawn_settings = ue.get_editor_world().actor_spawn(StaticMeshActor)
                    spawn_settings.attach_to_actor(props_cube)
                    spawn_settings.set_actor_scale(Scale, -Scale, Scale)
                    spawn_settings.set_actor_location(PosX, PosY, PosZ)
                    spawn_settings.set_actor_rotation(-RotX, -RotY, RotZ)
                    spawn_settings.StaticMeshComponent.StaticMesh = asset

                    spawn_settings.set_actor_label(f"{name}{current_number}")
                    continue

                except:
                    print(f"Seems like {name} is not imported!!")
                    continue

        props_cube.set_actor_scale(1,-1,1)


class geometry:
    #Import textures and materials for geometry. The reason for its own separate function is that I will have to do this part for both states of "individual_geometry_objects"
    #Both states require the same method to import geometry, so, i decided to not have to write this part twice.
    def import_materials(map_name, map_folder, import_folder, greyhound_folder, assets_folder, global_opacity, opacity_items):

        with open(f"{map_folder}\\{map_name}_matdata.json", "r") as file:
            mat_data = json.load(file)

        for textures in mat_data['Materials'].values():
            for texture_name in textures.values():
                import_texture(texture_name, import_folder, greyhound_folder, assets_folder)

        #Create materials
        for slot, texture in mat_data['Materials'].items():

            slot_name = clean(slot)

            try:
                check_material_existance(slot_name, import_folder, assets_folder, global_opacity, opacity_items)

            except:

                master_material = select_master_material(global_opacity, opacity_items, slot_name, import_folder, assets_folder)
                material_instance = ue.create_material_instance(master_material, f"{import_folder}materials/", slot_name)

                if 'Color Map' in texture:

                    texture_name = clean(texture['Color Map'])

                    current_texture = ue.load_object(texture_class, f"{import_folder}textures/{texture_name}.{texture_name}" )
                    material_instance.set_material_texture_parameter('AlbedoTexture', current_texture)

                if 'Normal Map' in texture:

                    texture_name = clean(texture['Normal Map'])

                    current_texture = ue.load_object(texture_class, f"{import_folder}textures/{texture_name}.{texture_name}" )
                    material_instance.set_material_texture_parameter('NormalTexture', current_texture)

                if 'Specular Map' in texture:
                    texture_name = clean(texture['Specular Map'])


                    current_texture = ue.load_object(texture_class, f"{import_folder}textures/{texture_name}.{texture_name}" )
                    material_instance.set_material_static_switch_parameter('Specular', True)
                    material_instance.set_material_texture_parameter('SpecularTexture', current_texture)


    #Re-assign parent of instances, useful if someone goes from global_opacity to not having global_opacity (and the opossite)
    def re_parent_materials(map_name, map_folder, import_folder, greyhound_folder, assets_folder, global_opacity, opacity_items):

        #Get all basic necesasry info
        with open(f"{map_folder}\\{map_name}_matdata.json", "r") as file:
            mat_data = json.load(file)

        #Use the info
        for slot in mat_data['Materials']:
            slot = clean(slot)

            check_material_existance(slot, import_folder, assets_folder, global_opacity, opacity_items)



    def _import(map_name, map_folder, import_folder, greyhound_folder, assets_folder, global_opacity, opacity_items):

        with open(f"{map_folder}\\{map_name}_matdata.json", "r") as file:
            mat_data = json.load(file)

        not_imported = False
        for model in mat_data['Materials']:
            model_name = clean(model)

            try:
                ue.load_object(mesh_class, f"{import_folder}MapGeo/{map_name}/{map_name}_{model_name}.{map_name}_{model_name}")

            except:
                not_imported = True
                break

        if not_imported:
            fbx_factory = PyFbxFactory()
            obj = f"{map_folder}\\{map_name}.obj"

            # configure the factory
            fbx_factory.ImportUI.bCreatePhysicsAsset = False
            fbx_factory.ImportUI.bImportMaterials = False
            fbx_factory.ImportUI.bImportTextures = False
            fbx_factory.ImportUI.bImportAnimations = False
            fbx_factory.ImportUI.StaticMeshImportData.bCombineMeshes = False
            fbx_factory.ImportUI.SkeletalMeshImportData.ImportUniformScale = 1;

            mesh = fbx_factory.factory_import_object(obj, f"{import_folder}MapGeo/{map_name}")

        #Import materials and assign them
        geometry.import_materials(map_name, map_folder, import_folder, greyhound_folder, assets_folder, global_opacity, opacity_items)

        model_names = []
        with open(f"{map_folder}\\{map_name}.obj") as obj_info:

            for _line in obj_info.readlines():

                line = _line.strip()

                if line .startswith("g "):

                    model_name = line[line.rfind(" ") + 1:]

                    if model_name not in model_names:
                        model_names.append(model_name)

        for material_info in model_names:

            model_slot = clean(material_info)
            material_name = model_slot
            model_name = f"{map_name}_{clean(material_info)}"


            #Actually start assigning the material
            asset = ue.load_object(mesh_class, f"{import_folder}MapGeo/{map_name}/{model_name}.{model_name}")
            selected_material = ue.load_object(material_instance_class, f"{import_folder}materials/{material_name}.{material_name}")

            for index, material in enumerate(asset.StaticMaterials):
                if model_slot in material.MaterialSlotName:
                    if material.MaterialInterface != selected_material:
                        asset.set_material(index, selected_material)

    #Only returns list if create_obj is set to false. Name of the function is pretty self explanatory.
    def import_individual_geometry(create_obj, map_name, map_folder, import_folder, greyhound_folder, assets_folder, individual_geometry_objects, global_opacity, opacity_items):


        individual_obj_name = f"io_{map_name}"

        models = []
        with open(f"{map_folder}\\{map_name}.obj") as og_obj_info:

            if create_obj:
                new_temporal_obj = open(f"{map_folder}\\{individual_obj_name}.obj", "a")

            for _line in og_obj_info.readlines():

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

                    if create_obj:
                        new_temporal_obj.write(f"g {model_info['Model']}{model_info['Number']}\n")

                elif create_obj:
                    new_temporal_obj.write(line + "\n")

            if create_obj:
                new_temporal_obj.close()

            else:
                return models


        #Import geometry
        not_imported = False

        for model in models:
            for number in range(1, model['Number'] + 1):
                model_name = clean(f"{individual_obj_name}_{model['Model']}{number}")

                try:
                    ue.load_object(mesh_class, f"{import_folder}MapGeo/io_{map_name}/{model_name}.{model_name}")

                except:
                    not_imported = True
                    break

        if not_imported:

            #Import geometry
            fbx_factory = PyFbxFactory()
            obj = f"{map_folder}\\{individual_obj_name}.obj"

            # configure the factory
            fbx_factory.ImportUI.bCreatePhysicsAsset = False
            fbx_factory.ImportUI.bImportMaterials = False
            fbx_factory.ImportUI.bImportTextures = False
            fbx_factory.ImportUI.bImportAnimations = False
            fbx_factory.ImportUI.StaticMeshImportData.bCombineMeshes = False
            fbx_factory.ImportUI.SkeletalMeshImportData.ImportUniformScale = 1;

            mesh = fbx_factory.factory_import_object(obj, f"{import_folder}MapGeo/{individual_obj_name}")

            os.remove(f"{map_folder}\\{individual_obj_name}.obj")

            #Import materials and assign them
            geometry.import_materials(map_name, map_folder, import_folder, greyhound_folder, assets_folder, global_opacity, opacity_items)

        for material_info in models:
            for model_number in range(1, material_info['Number'] + 1):

                model_name_only = clean(material_info['Model'])
                material_name = model_name_only
                model_name = f"{individual_obj_name}_{model_name_only}{model_number}"

                #Actually start assigning the material
                asset = ue.load_object(mesh_class, f"{import_folder}MapGeo/{individual_obj_name}/{model_name}.{model_name}")
                selected_material = ue.load_object(material_instance_class, f"{import_folder}materials/{material_name}.{material_name}")

                for index, material in enumerate(asset.StaticMaterials):
                    if model_name_only in material.MaterialSlotName:
                        if material.MaterialInterface != selected_material:
                            asset.set_material(index, selected_material)


    #Place geometry (applies for both individual and not individual objects geometry)
    def place(map_name, map_folder, import_folder, greyhound_folder, assets_folder, individual_geometry_objects, global_opacity, opacity_items):

        cube_placeholder = ue.load_object(StaticMesh, '/Engine/BasicShapes/Cube.Cube')

        geometry_cube = ue.get_editor_world().actor_spawn(StaticMeshActor, FVector(0, 0, 0), FRotator(0, 0, 0))
        geometry_cube.StaticMeshComponent.StaticMesh = cube_placeholder
        geometry_cube.set_actor_label('Map_Geometry')

        if individual_geometry_objects:

            #Check if everything is imported
            models = geometry.import_individual_geometry(False, map_name, map_folder, import_folder, greyhound_folder, assets_folder, individual_geometry_objects, global_opacity, opacity_items)

            #Import geometry
            not_imported = False

            io_map_name = f"io_{map_name}"

            for model in models:
                for number in range(1, model['Number'] + 1):
                    model_name = clean(f"{io_map_name}_{model['Model']}{number}")

                    try:
                        ue.load_object(mesh_class, f"{import_folder}MapGeo/{io_map_name}/{model_name}.{model_name}")

                    except:
                        not_imported = True
                        break

            if not_imported:
                print("Seems like the geometry is not imported! (or not imported correctly)")

            #If it is imported then place it
            else:

                individual_geometry_models = geometry.import_individual_geometry(False, map_name, map_folder, import_folder, greyhound_folder, assets_folder, individual_geometry_objects, global_opacity, opacity_items)

                for geometry_info in individual_geometry_models:
                    for model_number in range(1, geometry_info['Number'] + 1):

                        full_asset_name = clean(f"{io_map_name}_{geometry_info['Model']}{model_number}")

                        asset = ue.load_object(StaticMesh, f"{import_folder}MapGeo/{io_map_name}/{full_asset_name}.{full_asset_name}")

                        geometry_settings = ue.get_editor_world().actor_spawn(StaticMeshActor)
                        geometry_settings.attach_to_actor(geometry_cube)
                        geometry_settings.set_actor_scale( 0.3937, 0.3937, 0.3937 );
                        geometry_settings.StaticMeshComponent.StaticMesh = asset
                        geometry_settings.set_actor_label(clean(f"{geometry_info['Model']}{model_number}"))

        else:

            with open(f"{map_folder}\\{map_name}_matdata.json", "r") as file:
                mat_data = json.load(file)

            #Check if everything is imported correctly
            not_imported = False
            for model in mat_data['Materials']:
                model_name = clean(model)

                try:
                    ue.load_object(mesh_class, f"{import_folder}MapGeo/{map_name}/{map_name}_{model_name}.{map_name}_{model_name}")

                except:
                    not_imported = True
                    break

            if not_imported:
                print("Seems like the geometry is not imported! (or not imported correctly)")

            #If it is imported then place it
            else:
                for model_name in mat_data['Materials']:

                    full_asset_name = clean(f"{map_name}_{model_name}")

                    asset = asset = ue.load_object(StaticMesh, f"{import_folder}MapGeo/{map_name}/{full_asset_name}.{full_asset_name}")

                    geometry_settings = ue.get_editor_world().actor_spawn(StaticMeshActor)
                    geometry_settings.attach_to_actor(geometry_cube)
                    geometry_settings.set_actor_scale( 0.3937, 0.3937, 0.3937 );
                    geometry_settings.StaticMeshComponent.StaticMesh = asset
                    geometry_settings.set_actor_label(full_asset_name)
