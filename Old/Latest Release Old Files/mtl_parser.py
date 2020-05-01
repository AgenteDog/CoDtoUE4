geo_mtl_file = r"E:\Drone\mp_drone\mp_drone.mtl"

#5. Map Geometry
#First parsing all the slots, textures, etc.
geo_slots = []
geo_albedos = []

with open(geo_mtl_file, 'r') as file:

    for line in file.readlines():
        geo_slot = {}
        geo_albedo = {}

        _line = line.strip()

        if _line.startswith("newmtl"):
            geo_slot_name = _line[_line.rfind(" ") + 1:]

            geo_slot_name = geo_slot_name.replace('~', '_')
            geo_slot_name = geo_slot_name.replace('#', '_')
            geo_slot_name = geo_slot_name.replace('$', '_')
            geo_slot_name = geo_slot_name.replace('&', '_')

            geo_slot['Name'] = geo_slot_name
            geo_slots.append(geo_slot)

        elif _line.startswith("map_Kd"):
            geo_albedo_name = _line[_line.rfind(r"\\") + 2:]
            geo_albedo_name = geo_albedo_name[:geo_albedo_name.rfind(".png")]

            geo_albedo_name = geo_albedo_name.replace('~', '_')
            geo_albedo_name = geo_albedo_name.replace('#', '_')
            geo_albedo_name = geo_albedo_name.replace('$', '_')
            geo_albedo_name = geo_albedo_name.replace('&', '_')

            geo_albedo['Name'] = geo_albedo_name
            geo_albedos.append(geo_albedo)

for slot, albedo in zip(geo_slots, geo_albedos):
    print(slot['Name'])
