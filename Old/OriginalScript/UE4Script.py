import unreal
import json
import math

json_file = None
def jsonfile(filejson):
    global json_file
    json_file = filejson
    print('The location of the json file has been changed to ' + json_file)

map_folder = None
def xmodels(foldermap):
    global map_folder
    map_folder = foldermap
    print('The location of the xmodels folder has been changed to ' + map_folder)

_LOD0 = True
def lod(lodvalue):
    global _LOD0
    _LOD0 = lodvalue
    if lodvalue == True:
        print('Files that end with "_LOD0" has been set to True.')
    elif lodvalue == False:
        print('Files that end with "_LOD0" has been set to False.')
    else:
        print('The value has to be "True" or "False", please set this function to one of those values in order for this function to work.')


editorpath = 'CoD/xmodels/'
def savepath(path):
    global editorpath
    editorpath = path + '/'
    print('The save path has now been set to ' + '"' + editorpath + '"')

def PlaceAssets():
    if json_file is not None:
        with open(json_file, 'r') as file:
            entities = json.load(file)
        if _LOD0 == True:
            for propinfo in entities:
                actor_class = unreal.EditorAssetLibrary.load_asset("StaticMesh'" + '/Game/' + editorpath + propinfo['Name'] + '/' + propinfo['Name'] + '_LOD0' + '.' + propinfo['Name'] + "_LOD0'")
                actor_location = float(propinfo['PosX']) * 2.54, float(propinfo['PosY']) * 2.54, float(propinfo['PosZ']) * 2.54
                RotX = (float(propinfo['RotX'])) * 180/math.pi
                RotY = (float(propinfo['RotY'])) * 180/math.pi
                RotZ = (float(propinfo['RotZ'])) * 180/math.pi
                actor_rotation = RotY, RotZ, RotX
                actor_scale = float(propinfo['Scale']), -(float(propinfo['Scale'])), (float(propinfo['Scale']))
                myActor = unreal.EditorLevelLibrary.spawn_actor_from_object(actor_class, actor_location, actor_rotation)
                myActor.root_component.set_relative_scale3d(actor_scale)
        elif _LOD0 == False:
            for propinfo in entities:
                actor_class = unreal.EditorAssetLibrary.load_asset("StaticMesh'" + '/Game/' + editorpath + propinfo['Name'] + '/' + propinfo['Name'] + '.' + propinfo['Name'])
                actor_location = float(propinfo['PosX']) * 2.54, float(propinfo['PosY']) * 2.54, float(propinfo['PosZ']) * 2.54
                RotX = (float(propinfo['RotX'])) * 180/math.pi
                RotY = (float(propinfo['RotY'])) * 180/math.pi
                RotZ = (float(propinfo['RotZ'])) * 180/math.pi
                actor_rotation = RotY, RotZ, RotX
                actor_scale = (float(propinfo['Scale'])), -(float(propinfo['Scale'])), (float(propinfo['Scale']))
                myActor = unreal.EditorLevelLibrary.spawn_actor_from_object(actor_class, actor_location, actor_rotation)
                myActor.root_component.set_relative_scale3d(actor_scale)
    else:
        print('You need to add a location for the json_file.')


props = []
def ImportAssets():
    if json_file is not None:
        if map_folder is not None:
            with open(json_file, 'r') as file:
                entities = json.load(file)
            if _LOD0 == True:
                for propinfo in entities:
                    prop = {}
                    prop['Prop'] = propinfo['Name']
                    if prop not in props:
                        static_mesh = map_folder + '/' + propinfo['Name'] + '/' + propinfo['Name'] + '_LOD0.obj'
                        static_mesh_task = buildImportTask(static_mesh, '/Game/' + editorpath + propinfo['Name'], buildStaticMeshImportOptions())
                        executeImportTasks([static_mesh_task])
                        props.append(prop)
                    else:
                        continue
            elif _LOD0 == False:
                for propinfo in entities:
                    prop = {}
                    prop['Prop'] = propinfo['Name']
                    if prop not in props:
                        static_mesh = map_folder + '/' + propinfo['Name'] + '/' + propinfo['Name'] + '.obj'
                        static_mesh_task = buildImportTask(static_mesh, '/Game/' + editorpath + propinfo['Name'], buildStaticMeshImportOptions())
                        executeImportTasks([static_mesh_task])
                        props.append(prop)
                    else:
                        continue
        else:
            print('You need to add a location for the xmodels folder.')
    else:
        print('You need to add a location for the json_file.')

def buildImportTask(filename, destination_path, options=None):
    task = unreal.AssetImportTask()
    task.set_editor_property('automated', True)
    task.set_editor_property('destination_name', '')
    task.set_editor_property('destination_path', destination_path)
    task.set_editor_property('filename', filename)
    task.set_editor_property('replace_existing', True)
    task.set_editor_property('save', True)
    task.set_editor_property('options', options)
    return task

def buildStaticMeshImportOptions():
    options = unreal.FbxImportUI()
    options.set_editor_property('import_mesh', True)
    options.set_editor_property('import_textures', True)
    options.set_editor_property('import_materials', True)
    options.set_editor_property('import_as_skeletal', False)
    options.static_mesh_import_data.set_editor_property('import_translation', unreal.Vector(0.0, 0.0, 0.0))
    options.static_mesh_import_data.set_editor_property('import_rotation', unreal.Rotator(0.0, 0.0, 0.0))
    options.static_mesh_import_data.set_editor_property('import_uniform_scale', 1.0)
    options.static_mesh_import_data.set_editor_property('combine_meshes', True)
    options.static_mesh_import_data.set_editor_property('generate_lightmap_u_vs', False)
    options.static_mesh_import_data.set_editor_property('auto_generate_collision', True)
    return options

def executeImportTasks(tasks):
    unreal.AssetToolsHelpers.get_asset_tools() .import_asset_tasks(tasks)
