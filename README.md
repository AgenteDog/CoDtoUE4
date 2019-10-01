**Important**
I DO NOT this tool being used to put maps in other games that are not cod in any way, shape or form. 


If you need help/assistance make sure to join this Discord server: https://discordapp.com/invite/wUqukba

In case you are wondering, this tool works for Unreal Engine 4.21 or above.

# HOW TO USE
First you will need the DogModifiedC2M and [Greyhound](https://github.com/Scobalula/Greyhound) to export the assets needed. The download link for Greyhound is in this download in the form of a shortcut, the DogModifiedC2M also comes with this download. First use the DogModifiedC2M:

It will create 2 files (that are important);
mp_mapname_xmodelList.txt - Use this file as a filter in Greyhound to extract necessary models only
mp_mapname_xmodels.json - Used by my UE script to place models in the level.

Then you have to use Greyhound to export assets like the map geometry or the props. You have to export as obj.) After all assets are exported and ready, come back and keep reading. 

Now open Unreal Engine. Create a new project ( or open one if you want to ) and go to the plugin options. Here activate the Scripting plugins. To do this just “Click settings in the toolbar > Plugins > Scroll Down on the built in section > Scripting” and activate all in there.

It will ask you to restart the program so just click restart. After the project has loaded again go to “Edit > Project Settings” and scroll to the bottom.

In the additional paths just paste the location of where the UE4Script is located and activate Developer mode. It will ask you again to restart the project so just click restart.

 After this open the output log (Windows > Developer Tools > Output log) and choose Python. Now just type “import UE4Script” and hit enter.

Now there are certain functions that you **have** to input in the console **before** starting to import/place assets.

1. UE4Script.jsonfile(r’*Location/mp_mapname_xmodels.json*’) - Location of the .json file that C2M created.
   * Make sure to not delete the r’’ inside the parenthesis. Put the location inside the quotes.
   * Also make sure to add “ */mp_mapname.json*” at the end. This tells the script the name/extension of the file.
 
2. UE4Script.xmodels(r’*Location*’) - Location of the xmodels folder created by Greyhound.
   * Make sure to not delete the r’’ inside the parenthesis. Put the location inside the quotes.

Besides all of this, there are certain **optional** options that may be useful when importing/placing assets.

1. UE4Script.lod(*True or False*) - Tells the script if the props end with “_LOD0” or not.
   * This function is set to True by default.
   * Important: If you change this value, import props, and close UE, the next time you open UE you will have to set it to whatever
     value you had before closing the program in order to be able to place props.
     
2. UE4Script.savepath(r’*path*’) - Lets you select the location in which the files will be saved/are saved inside UE.
   * This function is set to “CoD/xmodels/” by default.
   * Important: If you change the path, import props, and close UE, the next time you open UE you will have to set it to whatever path        you had before closing the program in order to be able to place props.


 Once you have done all of this you can type UE4Script.ImportAssets() to start importing all props.

When the import is done (and you want to place assets) create a new empty level and type “UE4Script.PlaceAssets()” 

Unreal will freeze for about 5 to 10 minutes, don't panic. This is normal since it is placing hundreds of assets. If you want to know when it's done just open the task manager and when it stops saying “Not responding” it means it is done. ( In future updates I plan to add a progress bar.) You will notice all the props have been placed. Now just import the map geometry and done. You now have a Call of Duty map importer on Unreal Engine.

*Note: Sometimes the map may be flipped in the Y axis. To fix this make a cube, put it at the coordinates 0,0,0, parent all props (and map geometry) to it and set the Y axis to -1.*

In a non so distant future I will be implementing the script as a plugin for UE, this way its more user-friendly. For now I prefer to release this way so it can be tested on all cods, so bugs can be fixed, etc. 

# EXTRA INFO:
As of now the tool can import all games that Husky can make a .map of.  The tool has not been tested with all CoDs yet so there may be some bugs, if so please make sure to report it.

 The materials are imported like any other material would do, right now I don't use any type of master material to make instances of.  This tool is still in development and many changes, bug fixes, and etc will come.
