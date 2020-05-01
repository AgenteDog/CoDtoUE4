import unreal_engine as ue
from unreal_engine.classes import Blueprint
from unreal_engine import FVector, FRotator
from unreal_engine.classes import StaticMeshActor, StaticMesh
import json, os, glob, math

geo_map = "mp_hijacked"
geo_directory = r"E:\Bored\hijacked"
xmodels_path = r"/Game/CoD/"
extension = ".tga"


geo_folder = geo_directory + "\\" + geo_map + "\\"
geo_mtl_file = geo_directory + "\\" + geo_map + "\\" + geo_map + ".mtl"


xmodels_directory = geo_directory + r"\xmodels"
xmodels_json = geo_directory + "\\" + geo_map + "\\" + geo_map + "_xmodels.json"

with open(xmodels_json, 'r') as file:
    entities = json.load(file)

cube_placeholder = ue.load_object(StaticMesh, '/Engine/BasicShapes/Cube.Cube')
cube = ue.get_editor_world().actor_spawn(StaticMeshActor, FVector(0, 0, 0), FRotator(0, 0, 0))
cube.StaticMeshComponent.StaticMesh = cube_placeholder
cube.set_actor_label('map_cube')

mesh_number = 0
last_mesh = ''
try:
    for actor in entities:
        if not actor.get('Name'):
            continue

        #Set all the coordinates, scale and rotations.
        RotX = (float(actor['RotX'])) * math.pi/180
        RotY = (float(actor['RotY'])) * math.pi/180
        RotZ = (float(actor['RotZ'])) * math.pi/180

        RotX = RotX * 180/math.pi
        RotY = RotY * 180/math.pi
        RotZ = RotZ * 180/math.pi

        PosX = float(actor['PosX']) * 2.54
        PosY = float(actor['PosY']) * 2.54
        PosZ = float(actor['PosZ']) * 2.54

        Scale = float(actor['Scale'])

        #Place the mesh
        mesh = ue.load_object(StaticMesh, xmodels_path + 'xmodels' + '/' + actor['Name'] + '.' + actor['Name'])
        obj = ue.get_editor_world().actor_spawn(StaticMeshActor)
        obj.attach_to_actor(cube)
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

except:
    cube.set_actor_scale(1, -1, 1)


mesh = ue.load_object(StaticMesh, xmodels_path + 'MapGeo' + '/' + geo_map + '.' + geo_map)
obj = ue.get_editor_world().actor_spawn(StaticMeshActor)
obj.StaticMeshComponent.StaticMesh = mesh
obj.set_actor_label("Map Geometry")
