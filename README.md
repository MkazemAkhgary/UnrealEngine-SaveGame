# UnrealEngine-SaveGame
a simple way to save properties on Actors/Components marked with SaveGame flag.

# How to install

 - Put Public and Private content into your game/plugin module. 
 - Go to header files and replace YOUR_API with [name-of-your-module]_API

# What can be saved

Properties of Actors/Components marked with SaveGame flag can be saved. 
This works for actors/components that exist in the map and not spawned at runtime. 

![image](https://user-images.githubusercontent.com/15255162/175766222-0d1e8263-a9de-414c-8d19-91daa66be8ed.png)

# How to Save

 - Create Save Game of type "ObjectSaveGame"
 - Call SaveActor to save properties. you can save multiple actors on one SaveGame
 - Call SaveGameToSlot to save on disk

![image](https://user-images.githubusercontent.com/15255162/175766580-751ab8d6-0c6a-4f5c-8a00-f14bc03bd7f1.png)


# How to Load

 - Call LoadGameFromSlot to load data from disk
 - Cast to "ObjectSaveGame"
 - Call LoadActor to load properties of the given actor.

![image](https://user-images.githubusercontent.com/15255162/175766605-f3b257d9-83e4-4a29-9074-4c5c990a1135.png)

