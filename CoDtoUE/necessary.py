#All initial necessary stuff
import glob, os, json, math, shutil
import unreal_engine as ue
from unreal_engine.classes import Actor, Character, PyFbxFactory, TextureFactory, Material, StaticMesh, Blueprint, StaticMeshActor
from unreal_engine.structs import StaticMaterial, MeshUVChannelInfo
from unreal_engine import FVector, FRotator

mesh_class = ue.find_class("StaticMesh")
material_class = ue.find_class("Material")
texture_class = ue.find_class("Texture2D")
material_instance_class = ue.find_class("MaterialInstanceConstant")

#Make a list with all the greyhound files info (all textures, obj files, etc).
def files_list(path):

    all_files = []

    for root, directories, files in os.walk(path):
        for file_name in files:
            file = {}

            if file_name.endswith(".obj"):
                file['Type'] = "obj"

            elif file_name.endswith(".mtl"):
                file['Type'] = "mtl"

            elif file_name.endswith(".tga") or file_name.endswith(".png"):
                file['Type'] = "texture"

            else:
                file['Type'] = "other"

            file['Full Directory'] = os.path.join(root, file_name)
            file['Raw Name'] = file_name

            file_name = file_name[:file_name.rfind(".")]

            file['Original Name'] = file_name

            if "_LOD0" in file_name:
                file_name = file_name[:file_name.rfind("_LOD0")]

            file['Name'] = file_name
            file['Directory'] = root

            all_files.append(file)

    return all_files


#Fix text so that it is usable on ue4
def clean(text):
    new_text = text.replace('~', '_').replace('#', '_').replace('$', '_').replace('&', '_').replace('.', '').replace('\\', '')

    if new_text.startswith("ml"):
        new_text = new_text.replace("ml", '')

    return new_text

#Select master material
def select_master_material(global_opacity, opacity_items, name, import_folder, assets_folder):

    if not global_opacity:
        if any(item in name for item in (opacity_items)):
             return ue.load_object(material_class, f"{assets_folder}MasterMat_Opacity.MasterMat_Opacity")

        else:
            return ue.load_object(material_class, f"{assets_folder}MasterMat.MasterMat")

    else:
        return ue.load_object(material_class, f"{assets_folder}MasterMat_Opacity.MasterMat_Opacity")


#Import textures
def import_texture(texture_name, import_folder, greyhound_folder, assets_folder):

    texture_clean = clean(texture_name)

    try:
        #Check if textures exists
        ue.load_object(texture_class, f"{import_folder}textures/{texture_clean}.{texture_clean}")

    except:

        texture_found = False
        #If it does not exist, import it. if the texture is also not avialable for import then import the missing texture

        for file in files_list(greyhound_folder):
            if file['Name'] == texture_name and file['Type'] == "texture":
                texture_found = True
                texture_directory = file['Full Directory']

                texture_factory = TextureFactory()
                texture_factory.OverwriteYesOrNoToAllState = 2
                texture = texture_factory.factory_import_object(texture_directory, f"{import_folder}textures")
                texture.save_package()

                break

        if not texture_found:
            ue.duplicate_asset(f"{assets_folder}missing.missing", f"{import_folder}textures/{texture_clean}", texture_clean)


#This basically takes the necessary things and places them, that way the process is not manual.
#I know it looks like a lot of unncesary code, but, this will make everything not crash. Its necesssary since this files are the most imporant ones.
def PlaceAssetsFolder(assets_folder, assets_folder_dir, current_path):

        #Import stuff
        #You might notice I have "assets_folder[:-1]", this is because assets_folder ends with / and UE4 does not like that for imports, so, I remove it.
        texture_factory = TextureFactory()
        texture_factory.OverwriteYesOrNoToAllState = 2

        #import missing texture
        try:
            ue.load_object(texture_class, f"{assets_folder}missing.missing")
        except:
            texture = texture_factory.factory_import_object(f"{current_path}\\AssetsFolder\\missing.tga", f"{assets_folder[:-1]}")
            texture.save_package()


        #import flat normal
        try:
            ue.load_object(texture_class, f"{assets_folder}flat_normal.flat_normal")
        except:
            texture = texture_factory.factory_import_object(f"{current_path}\\AssetsFolder\\flat_normal.tga", f"{assets_folder[:-1]}")
            texture.save_package()

        #import white texture
        try:
            ue.load_object(texture_class, f"{assets_folder}White.White")
        except:
            texture = texture_factory.factory_import_object(f"{current_path}\\AssetsFolder\\White.tga", f"{assets_folder[:-1]}")
            texture.save_package()


        #import uassets (materials)
        #Copy uassets and put them in UE's folder. I know its a bit too much for such a simple task but its better to prevent crashes.
        try:
            os.makedirs(assets_folder_dir)
        except:
            pass

        SRC_DIR = f"{current_path}\\AssetsFolder\\uasset"
        TARG_DIR = assets_folder_dir

        GLOB_PARMS = "*"

        for file in glob.glob(os.path.join(SRC_DIR, GLOB_PARMS)):
            if file not in glob.glob(os.path.join(TARG_DIR, GLOB_PARMS)):

                try:
                    shutil.copy(file,TARG_DIR)
                except:
                    pass


        #Import error fbx file
        try:
            ue.load_object(mesh_class, f"{assets_folder}error.error")
        except:
            fbx_factory = PyFbxFactory()
            obj = f"{current_path}\\AssetsFolder\\error.fbx"

            #configure the factory
            fbx_factory.ImportUI.bCreatePhysicsAsset = False
            fbx_factory.ImportUI.bImportMaterials = False
            fbx_factory.ImportUI.bImportTextures = False
            fbx_factory.ImportUI.bImportAnimations = False
            fbx_factory.ImportUI.StaticMeshImportData.bCombineMeshes = True
            fbx_factory.ImportUI.SkeletalMeshImportData.ImportUniformScale = 1;

            mesh = fbx_factory.factory_import_object(obj, f"{assets_folder[:-1]}")
            mesh.save_package()


#Check if material exists and if it does check if the parent mat is correct.
def check_material_existance(name, import_folder, assets_folder, global_opacity, opacity_items, model = []):

    material = ue.load_object(material_instance_class, f"{import_folder}materials/{name}.{name}")


    if not global_opacity and any(item in name for item in (opacity_items)) or any(item in model for item in (opacity_items)):
        opacity_mat = ue.load_object(material_class, f"{assets_folder}MasterMat_Opacity.MasterMat_Opacity")
        if material.Parent != opacity_mat:
            material.set_material_parent(opacity_mat)


    elif not global_opacity:
        normal_mat = ue.load_object(material_class, f"{assets_folder}MasterMat.MasterMat")
        if material.Parent != normal_mat:
            material.set_material_parent(normal_mat)

    elif global_opacity:
        opacity_mat = ue.load_object(material_class, f"{assets_folder}MasterMat_Opacity.MasterMat_Opacity")
        if material.Parent != opacity_mat:
            material.set_material_parent(opacity_mat)



#Required for PyQt5
import sys
import unreal_engine as ue
import PySide2
from PySide2 import QtWidgets
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QApplication, QWidget, QInputDialog, QLineEdit, QFileDialog, QMainWindow, QMessageBox
from PyQt5.QtGui import QIcon

app = QtWidgets.QApplication(sys.argv)

def ticker_loop(delta_time):
    app.processEvents()
    return True

ticker = ue.add_ticker(ticker_loop)
