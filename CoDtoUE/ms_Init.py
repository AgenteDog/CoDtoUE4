#!/usr/bin/env python
# -*- coding: utf-8 -*-


"""
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

███╗   ███╗███████╗ ██████╗  █████╗ ███████╗ ██████╗ █████╗ ███╗   ██╗███████╗    ██╗███╗   ██╗████████╗███████╗ ██████╗ ██████╗  █████╗ ████████╗██╗ ██████╗ ███╗   ██╗
████╗ ████║██╔════╝██╔════╝ ██╔══██╗██╔════╝██╔════╝██╔══██╗████╗  ██║██╔════╝    ██║████╗  ██║╚══██╔══╝██╔════╝██╔════╝ ██╔══██╗██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║
██╔████╔██║█████╗  ██║  ███╗███████║███████╗██║     ███████║██╔██╗ ██║███████╗    ██║██╔██╗ ██║   ██║   █████╗  ██║  ███╗██████╔╝███████║   ██║   ██║██║   ██║██╔██╗ ██║
██║╚██╔╝██║██╔══╝  ██║   ██║██╔══██║╚════██║██║     ██╔══██║██║╚██╗██║╚════██║    ██║██║╚██╗██║   ██║   ██╔══╝  ██║   ██║██╔══██╗██╔══██║   ██║   ██║██║   ██║██║╚██╗██║
██║ ╚═╝ ██║███████╗╚██████╔╝██║  ██║███████║╚██████╗██║  ██║██║ ╚████║███████║    ██║██║ ╚████║   ██║   ███████╗╚██████╔╝██║  ██║██║  ██║   ██║   ██║╚██████╔╝██║ ╚████║
╚═╝     ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═══╝╚══════╝    ╚═╝╚═╝  ╚═══╝   ╚═╝   ╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝ taken over :0

>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

There used to be some cool info here, but, it was mostly contact information of Quixel. The plugin was modified by AgenteDog so just enter this link (https://discord.com/invite/c3eYJPM) for support :)
They did gave permision to modify/use this stuff in their source code.
"""


import unreal_engine as ue
import json, re, os, sys, asyncio, traceback, ctypes, time, clipboard, webbrowser, inspect, socket, threading, ue_asyncio
from pprint import pprint

from unreal_engine.enums import EMaterialSamplerType, EHorizontalAlignment, EVerticalAlignment

from unreal_engine import SWindow, SVerticalBox, SHorizontalBox, SButton, STextBlock, SBorder, FLinearColor, FMaterialEditorUtilities, FSlateIcon, FSlateStyleSet

from unreal_engine.structs import SlateBrush, SlateColor, Vector2D, SkeletalMaterial, MeshUVChannelInfo, ColorMaterialInput, VectorMaterialInput, ScalarMaterialInput, ExpressionInput

from unreal_engine.classes import MaterialInstanceConstant, MaterialInstance, StaticMeshActor, FoliageType
from unreal_engine.classes import StaticMesh, PyFbxFactory, MaterialExpressionTextureSample, MaterialFactoryNew, Material, TextureFactory, Texture2D

print('#'*20 + '-'*10 + 'Python Integration for Megascans Initialized' + '-'*10 + '#'*20)

custom_path = (r"CUSTOMPROJECTPATH" + "/")

if not os.path.exists(custom_path):
    path_ = (os.path.dirname(os.path.realpath('ms_Init')))
    path_ = os.path.split(os.path.split(path_)[0])[0]
    custom_path = os.path.join(path_, 'Plugins', 'UnrealEnginePython', '')


def ms_return_path():
    return custom_path

print(custom_path)

try:
    from PySide2.QtGui import *
    from PySide2.QtCore import *
    from PySide2.QtWidgets import *
except:
    ue.message_dialog_open(0, "C++ project detected, the integration UI is currently only available in a blueprint project.\n\
You can still use the plugin as normal, and expect C++ compatibility soon !")
    print('C++ Project Detected, UI not available in the current version.')
    pass
