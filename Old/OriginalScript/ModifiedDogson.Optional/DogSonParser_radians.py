import json
import os
import colorama
from colorama import Fore, Style
import sys
import math

colorama.init()

extention_choose = 'map'

mapfile = None
output = None
mapents = None
missing_file = False
mapents = None
mapentsfile = None


mapents = input('Do you want to also parse the mapents? (Yes/No): ')
if mapents.lower() == "no":
    mapents = False
elif mapents.lower() == 'yes':
    mapents = True
    mapentsfile_select = input('Please drag and drop the mapents file. ')
    mapfile_subtract = mapentsfile_select[mapentsfile_select.rfind('\\') + 1:]
    mapentsfile = mapfile_subtract[:mapfile_subtract.rfind('.')] + '.txt'
else:
    print(Fore.RED + 'You can only answer this question with a "Yes" or a "No"')
    os.system("pause")
    sys.exit()
mapfile =  input('Please drag an drop the map file. ')
mapfile_subtract = mapfile[mapfile.rfind('\\') + 1:]
mapfile = mapfile_subtract[:mapfile_subtract.rfind('.')] + '.map'

output = mapfile_subtract[:mapfile_subtract.rfind('.')]

# Read the json file---
if os.path.isfile(mapfile) == True and missing_file == False:
    with open(mapfile, 'r') as file: #Opens the file to read it
        entities = []
        entity = {}
        editor_block_started=False
        for line in file.readlines():
            _line = line.strip()
            if _line == '{':
                if not editor_block_started:
                    entity = {"modelscale": 1.0, "angles": '0 0 0', "model": None, "uniformscale": 1.0} #This is a list of default values for certain things
            elif _line == '}':
                if editor_block_started:
                    editor_block_started= False
                else:
                    entities.append(entity)
            elif _line in ('editor', 'side', 'solid'): #All stuff listed here will be ignored by the parser.
                editor_block_started = True
            else:
                try:
                    key, value = _line.split('" "')
                    entity[key[1:]] = value[:-1]
                except ValueError:
                    pass
    values = []
    models = []
    for entity in entities:
        if entity['model'] is None or entity['model'].startswith('sprites/'):
            continue
        value = {}
        modelscale = entity['uniformscale']
        if mapfile.endswith('.vmf'):
            modelscale = entity['uniformscale']
        elif mapfile.endswith('.map'):
            modelscale = entity['modelscale']
        x, y, z = entity['origin'].split()
        xr, yr, zr = entity['angles'].split()
        value['Name'] = entity['model'][entity['model'].rfind('/')+1:]
        value['PosX'] = f"{float(x):.4f}"
        value['PosY'] = f"{float(y):.4f}"
        value['PosZ'] = f"{float(z):.4f}"
        zrf = float(zr) * math.pi/180
        xrf = float(xr) * math.pi/180
        yrf = float(yr) * math.pi/180
        value['RotX'] = f"{float(zrf):.4f}"
        value['RotY'] = f"{float(xrf):.4f}"
        value['RotZ'] = f"{float(yrf):.4f}"
        value['Scale'] = f"{float(modelscale):.4f}"
        values.append(value)
        model = {}
        if extention_choose == 'map':
            model['Model'] = entity['model'][entity['model'].rfind('/')+1:]
            if model not in models:
                models.append(model)
                modelname = model['Model'] + ','
                modelfile = open(output + r"_xmodelslist.txt", 'a+')
                modelfile.write(modelname)
                modelfile.close()
    if extention_choose == 'map':
        modelfile = open(output + '_xmodelslist.txt', 'r+')
        content = modelfile.read()
        modelfile.truncate(0)
        modelfile.close()
        modelfile = open(output + '_xmodelslist.txt', 'r+')
        modelfile.write(content[:-1])
        modelfile.close()
    if extention_choose == 'map':
        print(Fore.GREEN + 'Models from the .map file parsed successfully.')
    elif extention_choose == 'vmf':
        print(Fore.GREEN + 'Models from the .vmf file parsed successfully.')
else:
    if extention_choose == 'map':
        print(Fore.RED + 'The .map file does not exist or is not in this directory.')
    elif extention_choose == 'vmf':
        print(Fore.RED + 'The .vmf file does not exist or is not in this directory.')
    missing_file = True

# Read the mapEnts file---
if mapents == True:
    if os.path.isfile(mapentsfile) == True and missing_file == False:
        with open(mapentsfile, 'r') as file:
            entities_mapents = []
            entity_mapents = {}
            editor_block_started=False
            for line in file.readlines():
                _line = line.strip()
                if _line == '{':
                    if not editor_block_started:
                        entity_mapents = {"modelscale": 1.0, "angles": '0 0 0', "model": None, "uniformscale": 1.0}
                elif _line == '}':
                    if editor_block_started:
                        editor_block_started= False
                    else:
                        entities_mapents.append(entity_mapents)
                elif _line in ('editor', 'side', 'solid'):
                    editor_block_started = True
                else:
                    try:
                        key, value = _line.split('" "')
                        entity_mapents[key[1:]] = value[:-1]
                    except ValueError:
                        pass
        values_mapents = []
        models = []
        for entity_mapents in entities_mapents:
            if entity_mapents['model'] is None or entity_mapents['model'].startswith('sprites/') or entity_mapents['classname'] != 'script_model':
                continue
            value_mapents = {}
            modelscale = entity_mapents['uniformscale']
            if mapfile.endswith('.vmf'):
                modelscale = entity_mapents['uniformscale']
            elif mapfile.endswith('.map'):
                modelscale = entity_mapents['modelscale']
            x, y, z = entity_mapents['origin'].split()
            xr, yr, zr = entity_mapents['angles'].split()
            value_mapents['Name'] = entity_mapents['model'][entity_mapents['model'].rfind('/')+1:]
            value_mapents['PosX'] = f"{float(x):.4f}"
            value_mapents['PosY'] = f"{float(y):.4f}"
            value_mapents['PosZ'] = f"{float(z):.4f}"
            zrf = float(zr) * math.pi/180
            xrf = float(xr) * math.pi/180
            yrf = float(yr) * math.pi/180
            value['RotX'] = f"{float(zrf):.4f}"
            value['RotY'] = f"{float(xrf):.4f}"
            value['RotZ'] = f"{float(yrf):.4f}"
            value_mapents['Scale'] = f"{float(modelscale):.4f}"
            values_mapents.append(value_mapents)
            model = {}
            if extention_choose == 'map':
                model['Model'] = entity_mapents['model'][entity_mapents['model'].rfind('/')+1:]
                if model not in models:
                    models.append(model)
                    modelname = model['Model'] + ','
                    modelfile = open(output + '_xmodelslist.txt', 'a+')
                    modelfile.write(modelname)
                    modelfile.close()
        if extention_choose == 'map':
            modelfile = open(output + '_xmodelslist.txt', 'r+')
            content = modelfile.read()
            modelfile.truncate(0)
            modelfile.close()
            modelfile = open(output + '_xmodelslist.txt', 'r+')
            modelfile.write(content[:-1])
            modelfile.close()
        print(Fore.GREEN + "Models from mapents file parsed successfully.")
    else:
        print(Fore.RED + 'The mapEnts file does not exist or is not in this directory.')
        missing_file = True

# Write it all on a json file.
if missing_file == True:
    print(Fore.RED + 'The json/xmodelslist file was not created.')
    if os.path.isfile(output + "_xmodelslist.txt") == True:
        os.remove(output + "_xmodelslist.txt")
    os.system("pause")
elif missing_file == False and extention_choose == 'map':
    if mapents == True:
        combined = values + values_mapents
        with open(output + '.json', 'w+') as file:
            json.dump((combined), file, indent=2)
    elif mapents == False:
        with open(output + '.json', 'w+') as file:
            json.dump((values), file, indent=2)
    os.system("pause")
elif extention_choose == 'vmf':
    with open(output + '.json', 'w+') as file:
        json.dump((values), file, indent=2)
    os.system("pause")
