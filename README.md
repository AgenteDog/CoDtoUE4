# CoDtoUE

I am proud to say that this small project went from a script to a plugin. This plugin is better, faster and more optimized than the script. The plugin is still in beta so you might encounter crashes, if you do please report how or when the crash happened in the issues tab.


### For what UE4 version is this plugin?

Currently, these are the Unreal Engine versions my plugin supports:
- 4.17
- 4.20
- 4.21
- 4.22
- 4.24

More versions will be supported soon.


### What does this plugin import?

This plugin imports:
- Props (with textures/materials)
- Map Geometry (with textures/materials)

It is important to note that the assets imported depend on C2M and not me. This means that if you see something like a prop that was not imported but that is in game: it is not up to me. This script only imports the things mentioned above that C2M is able to export. Things like particles (for example) are not imported.


### What cods does this script support?

As long as C2M can export a .json and Greyhound can export all files correctly it should be fine! If there is any cod that does not work even when this requirements are met tell me!

### Discord Server

You can join [this discord server](https://discord.gg/c3eYJPM) if you need to asks questions. If you are having problems with things like crashes, please open an issue in the issues tab.

## Steps to take before using the plugin:

#### You will need to download:

- [My plugin](https://github.com/AgenteDog/CoDtoUE4/releases)
- [Greyhound](https://github.com/Scobalula/Greyhound/releases) (Used to export models/textures from the games)
- [C2M](https://github.com/sheilan102/C2M) (used to export map info and map geometry)

If you want to know/learn how to use C2M and/or Greyhound: They have lots of documentation in their GitHub pages!

#### You will need to:
1. Export Greyhound and C2M necessary files. (make sure you export textures from greyhound with the \_images txt file enabled and that you also export map textures if you want to import map geometry)

Tip: Do not rename any of the files.
Tip2: I recommend exporting all game textures in order to make sure that there will not be any missing textures!

#### How to install my plugin:

1. Create a new UE4 project. (optional, you can use an existing one.)
2. Go to your project folder.
3. Create a new folder called "Plugins".
4. Unzip the downloaded .rar file in that folder.
5. You can now open your project.


## Using the plugin:

You will see a new icon in the toolbar that has as a logo with the words "CTU". Just click that button.

You will see this:

![](https://i.imgur.com/eRFkN8o.png)

This is what all the settings do:

- Map Obj: Here you will select the .obj file created by C2M.
- Greyhound Directory: Here you just put the folder in which greyhound is.
- Import Folder: The folder that will have all the imported files, **I recommend leaving this as default!**
- Import Props: Let's you decide if you want to import props or not.
- Import Geometry: Let's you decide if you want to import props or not. **IMPORTANT: OBJ FILES THAT ARE TOO BIG MIGHT CRASH UNREAL, IF YOUR UNREAL CRASHES TRY TURNING OFF THIS OPTION AND IMPORTING.**
- Individual Geometry Objects: This will divide all objects in the obj separately. This will add **significantly** more objects in the scene!
- Global Opacity: If turned on, all materials will be able to have transparency. If turned off, only objects that contain any of the words in the textbox below will be able to have transparency.
- Place Props: Let's you decide if you want to place props or not.
- Place Geometry: Let's you decide if you want to place geometry or not.

**IMPORTANT: MAKE SURE TO CLICK THE SAVE SETTINGS BUTTONS AFTER SETTING UP ALL YOUR SETTINGS, NOT DOING SO WILL NOT SAVE YOUR SETTINGS!**

This is what all the buttons do:
- Import: Imports everything, following the previously mentioned settings.
- Place: Places everything, following the previously mentioned settings.
- Re-Parent Materials: If you imported with Global Opacity on and your materials seem to be broken, you can de select the option and click this button. It will re-parent all your materials. This can also work in the opposite sense. If you want to use Global Opacity because while importing it was off you can just turn it on and click this button.
- Save Settings: Saves the current settings.


## Common issues that people have:

- When I press the Import (or place) button, nothing happens: This issue is not actually an issue, this happens when the plugin cant find one or multiple necessary files.

- Some textures are "white": These are not white textures, they are actually decals. You can replace this decals with the original texture. It is very likely that the material to replace this decal is alredy created.

- Unreal Engine crashes: If that happens, please report this in the issues tab! Make sure to say when the crash happened and what you did before the crash.
