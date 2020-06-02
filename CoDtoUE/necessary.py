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

    return new_text

#Select master material
def select_master_material(global_opacity, opacity_items, name, import_folder, assets_folder):

    if not global_opacity:
        if any(item in name for item in (opacity_items)):
            master_mat = ue.load_object(material_class, f"{assets_folder}MasterMat_Opacity.MasterMat_Opacity")

        else:
            master_mat = ue.load_object(material_class, f"{assets_folder}MasterMat.MasterMat")

    else:
        master_mat = ue.load_object(material_class, f"{assets_folder}MasterMat_Opacity.MasterMat_Opacity")

    return master_mat


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
                break


        if texture_found:
            texture_factory = TextureFactory()
            texture_factory.OverwriteYesOrNoToAllState = 2
            texture_factory.factory_import_object(texture_directory, f"{import_folder}textures")
            texture_factory.save_package()

        else:
            ue.duplicate_asset(f"{assets_folder}missing.missing", f"{import_folder}textures/{texture_clean}", texture_clean)


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
