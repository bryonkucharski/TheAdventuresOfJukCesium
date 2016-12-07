# The Adventures Of Juk Cesium
The Adventures of Juk Cesium is an Two-Dimensional Role Playing Game created in C++ using the Simple and Fast Multimedia Library (SFML). The main goal of the game is travel with Juk Cesium, the main player, across the world to interact with non player characters (NPC), monsters, and boss monsters. Shoot at enemies to increase your total experience, level, and damage. Travel to the Waterfall Corridor or Graveyard shed to fight a boss monster. 

# How to play
To play The Adventures of Juk Cesium, navigate to the "release" folder and download the res folder, the exe, and all the ddls

# How to develop
This game was developed in Visual Studio 2015 using the SFML libraries. For instructions and on how to develop in SFML using Visual Studio, visit the following link. http://www.sfml-dev.org/tutorials/2.4/start-vc.php

# Gameplay Screenshots
![Fighting](https://raw.githubusercontent.com/bryonkucharski/TheAdventuresOfJukCesium/master/SFML_RPG/SFML_RPG/res/GitHubPictures/Fighting%20General%20Enemies.PNG "Battle Scene")

![Fighting 2](https://raw.githubusercontent.com/bryonkucharski/TheAdventuresOfJukCesium/master/SFML_RPG/SFML_RPG/res/GitHubPictures/enemy%20shooting%20at%20an%20angle.PNG "Battle Scene 2")

![Market](https://raw.githubusercontent.com/bryonkucharski/TheAdventuresOfJukCesium/master/SFML_RPG/SFML_RPG/res/GitHubPictures/Hanging%20out%20with%20the%20sheep.PNG "Market")

# World Map
![World Map](https://raw.githubusercontent.com/bryonkucharski/TheAdventuresOfJukCesium/master/SFML_RPG/SFML_RPG/res/GitHubPictures/World%20Map.png "World Map")

# Class Outline
<b>Main</b> - Handles all game logic including menu screens, updating, drawing, and intersections that happen during the game. <br>
<b>Entity</b> - Parent class for most other classes. Contains the Texture, Sprite, Rectangle, and Text objects from the SFML Library. <br>
<b>Creature</b> - Anything that walks, shoots, speaks, moves, updates, etc. Parent class for Player, NPC, and Enemy. Contains the AI for Creature movement.<br>
<b>Player</b> - The main player that the game focuses on. Players move with WASD or Arrow keys and shoot with space. <br>
<b>Enemy</b> - Anything that an player can battle with. Contains different shooting AI to shoot at the Player. Enemy movements are based on a Creature AI.<br>
<b>NPC </b> - A person in the game who is not controlled by the user. The player may not attack an NPC and the NPC does not attack at the player or enemies.<br>
<b>Location</b> - A place for the main player to travel. A location holds the enemies, obstacles, and NPCs.<br>
<b>World</b> - The world is what holds all of the locations. All of the Enemy, NPC, and obstacle creations are done in the world. <br>
<b>Projectile</b> - A bullet from either the player or an enemy, which will intersect with an entity.<br>
<b>Menu</b> - Start Screen, Pause Screen, Game Over screen with four options to chose from.<br>
<b>GUIBar</b> - Contains all the pictures and text seen on the bottom of the screen.<br>
<b>Item</b> - Not implemented in the current release. This class contains an entity that an enemy can drop on death or a player can find in the game. <br>
<b>ItemList</b> - A static list of all Items that are currently in the game. Also not implemented. <br>
