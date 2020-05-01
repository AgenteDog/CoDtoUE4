# CoDtoUE4
*Requirements/Instructions for the original version are in its respective folder*

## You will need:

- [UnrealEnginePython](https://github.com/20tab/UnrealEnginePython) (Plugin that will run the script)
- [Greyhound](https://github.com/Scobalula/Greyhound/releases) (Used to export models/textures from the games)
- [C2M](https://github.com/sheilan102/C2M) (used to export map info and map geometry)

If you want to know/learn how to use the UnrealEnginePython plugin they have lots of documentation! Also, running the script is pretty much just copy/pasting and editing a few values.
*Same thing for C2M and Greyhound.*


## Steps to take before actually using the script:

 1. Export Greyhound and C2M necessary files. (make sure you expor textures with the _images txt file enabled)
 2. Create a main folder (you can name it whatever you want)
 3. Copy and paste the xmodels folder create by greyhound and the folder created by C2M on that folder.
 4. Take the error folder from **ImportedFiles.zip** and paste it inside the xmodels folder.
 5. Take the $black.TGA file (also from the **ImportedFiles.zip file) and paste it inside the _images folder that is inside the xmodels folder.
 
 Tip: Do not rename any of the files.
 Tip2: If you get any missing textures while importing I would recommend you to just export all the game textures and put them in the textures folder inside the _images folder.
 
 ## Actually using the script:
 
 I made sure that editing the script was as easy as possible! So it will not be hard at all! The previous steps explained where in fact to make things easier.
 
 This is how the code you need to modify looks:
 
 ```python
geo_map = "mp_hijacked"
geo_directory = r"E:\TEMPGROUND\hijacked"
xmodels_path = r"/Game/CoD/"
extension = ".tga"
```

You will find this in the Placing script and in the importing script.
Before explaining what everything is, make sure you only replace what is inside the quotes!!!

geo_map = Name (in the files) of the map. You will be able to know the name because the name of the folder created by C2M is the name of the map.

geo_directory = Directory of the main folder you created! (The one that contains the xmodels and the folder by C2M)

xmodels_path = This is where everything will get saved in UE4.

extension = Extension of the textures exported by greyhound. I recommend exporting textures in tga format.

###Optional settings

There is a bug with the textures on black ops 2 where some textures had transparency even if the textures were solid. This created a lot of bugged objects. My solution to this was to make a list of things that will have transparency.

```python
opacity = ("grass", "foliage", "glass", "paper")
```

Basically, if the material has any of those words in its name then transparency will be applied! This means that if the file is called "example_grass_example" then transparency will be aplied. Same thing if the material is called "examplegrassexample." As long as any of those words are in the material name, transparency will be applied.

If you need to add words you can just add a comma after the last word and add the word. Example: (..."paper", "example")

## Other:

This is old code so sorry if it is messy or if there is a lot of stuff that I could have done better. I know this code could be improved much more. 

If I ever feel the need to add updates to this and release it as a full plugin I will probably re-code the whoel thing. For now, this is fine.
 
**Also: TELL ME IF THERE ARE ANY BUGS!**
 
