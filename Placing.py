#Settings!
geo_map = "mp_village"
geo_directory = r"E:\Example\Standoff"
xmodels_path = r"/Game/CoD/"
extension = ".tga"

#Optional Settings!
import_geometry = True
individual_geometry_objects = False

import unreal_engine as ue
from unreal_engine.classes import Blueprint
from unreal_engine import FVector, FRotator
from unreal_engine.classes import StaticMeshActor, StaticMesh
import json, os, glob, math

geo_folder = geo_directory + "\\" + geo_map + "\\"
geo_mtl_file = geo_directory + "\\" + geo_map + "\\" + geo_map + ".mtl"


xmodels_directory = geo_directory + r"\xmodels"
xmodels_json = geo_directory + "\\" + geo_map + "\\" + geo_map + "_xmodels.json"

with open(xmodels_json, 'r') as file:
    entities = json.load(file)

cube_placeholder = ue.load_object(StaticMesh, '/Engine/BasicShapes/Cube.Cube')
props_cube = ue.get_editor_world().actor_spawn(StaticMeshActor, FVector(0, 0, 0), FRotator(0, 0, 0))
props_cube.StaticMeshComponent.StaticMesh = cube_placeholder
props_cube.set_actor_label('props')

mesh_number = 0
last_mesh = ''


for actor in entities:

    if 'Name' in actor:

        if actor['Name'].endswith("."):
            actor['Name'] = actor['Name'][:actor['Name'].rfind(".")]

        #Set all the coordinates, scale and rotations.
        if 'RotX' in actor:
            RotX = (float(actor['RotX'])) * math.pi/180
            RotY = (float(actor['RotY'])) * math.pi/180
            RotZ = (float(actor['RotZ'])) * math.pi/180

            RotX = RotX * 180/math.pi
            RotY = RotY * 180/math.pi
            RotZ = RotZ * 180/math.pi

        if 'PosX' in actor:
            PosX = float(actor['PosX'])
            PosY = float(actor['PosY'])
            PosZ = float(actor['PosZ'])

        if 'Scale' in actor:
            Scale = float(actor['Scale']) * 0.394

        #Place the mesh

        try:
            mesh = ue.load_object(StaticMesh, f"{xmodels_path}xmodels/{actor['Name']}.{actor['Name']}")
        except:
            mesh = ue.load_object(StaticMesh, f"{xmodels_path}xmodels/{actor['Name']}_missing.{actor['Name']}_missing")

        obj = ue.get_editor_world().actor_spawn(StaticMeshActor)
        obj.attach_to_actor(props_cube)
        obj.set_actor_scale(Scale, -Scale, Scale)
        obj.set_actor_location(PosX, PosY, PosZ)
        obj.set_actor_rotation(-RotX, -RotY, RotZ)
        obj.StaticMeshComponent.StaticMesh = mesh

        #Rename it
        if last_mesh == actor['Name']:
            mesh_number = mesh_number + 1
        else:
            mesh_number = 0
        last_mesh = actor['Name']

        if mesh_number == 0:
            obj.set_actor_label(actor['Name'])
        else:
            obj.set_actor_label(actor['Name'] + ' ' + str(mesh_number))

props_cube.set_actor_scale(1,-1,1)


if import_geometry:

    geo_cube = ue.get_editor_world().actor_spawn(StaticMeshActor, FVector(0, 0, 0), FRotator(0, 0, 0))
    geo_cube.StaticMeshComponent.StaticMesh = cube_placeholder
    geo_cube.set_actor_label('map_geometry')

    with open(f"{geo_folder}{geo_map}_matdata.json", "r") as file:
        geo_matfile = json.load(file)

    if not individual_geometry_objects:
        for slot in geo_matfile['Materials']:

            info_model = clean(f"{geo_map}_{slot}")

            mesh = ue.load_object(StaticMesh, f"{xmodels_path}MapGeo/{geo_map}/{info_model}.{info_model}")
            obj = ue.get_editor_world().actor_spawn(StaticMeshActor)
            obj.attach_to_actor(geo_cube)
            obj.set_actor_scale( 0.394, 0.394, 0.394 );
            obj.StaticMeshComponent.StaticMesh = mesh
            obj.set_actor_label(clean(slot))


    elif individual_geometry_objects:
        models = []

        with open(f"{geo_folder}{geo_map}.obj", 'r') as geo:

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

        geo_map = f"p_{geo_map}"

        if individual_geometry_objects:
            for material_info in models:
                for model_number in range(1, material_info['Number'] + 1):

                    info_model = clean(f"{geo_map}_{material_info['Model']}{model_number}")

                    mesh = ue.load_object(StaticMesh, f"{xmodels_path}MapGeo/{geo_map}/{info_model}.{info_model}")
                    obj = ue.get_editor_world().actor_spawn(StaticMeshActor)
                    obj.attach_to_actor(geo_cube)
                    obj.set_actor_scale( 0.394, 0.394, 0.394 );
                    obj.StaticMeshComponent.StaticMesh = mesh
                    obj.set_actor_label(clean(f"{material_info['Model']}{model_number}"))

print("Done!!")
