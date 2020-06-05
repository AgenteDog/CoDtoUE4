def split(objfile):
    import os
    models = []
    new_temporal_obj = open(f"{os.path.splitext(objfile)[0]}_new.obj", "w")

    with open(objfile) as og_obj_info:

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

                new_temporal_obj.write(f"g {model_info['Model']}{model_info['Number']}\n")

            else:
                new_temporal_obj.write(line + "\n")


    new_temporal_obj.close()
    print("OBJ file succesfully created!")
