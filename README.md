[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=23265906)
# chooseYourOwnAdventure
a game for cpsc-25 

Player.h defines the new Player object added to the game. The Player class stores the player’s name, health, and inventory. This object was added to make the game more interactive by allowing player progress to be tracked instead of only moving through rooms.

Player.cpp implements the behavior of the Player object. It includes functions for adding items to inventory, displaying inventory, taking damage, checking if the player is still alive, and returning player information. These functions were necessary to connect the new Player object to the game loop.

main.cpp was updated to integrate the new Player object into the game. A Player is now created at the start of the program and used throughout the room loop. Two new functions were added: pickUpItem() and showPlayerStatus(). These functions allow the player to collect items and view their health and inventory. The game was also improved by adding a health system and inventory system, making the adventure more interactive.

Room.h did not need major structural changes for the new object integration. It already provided the item and action data needed for the Player object to interact with rooms. The existing Room class was reused as part of the updated game design.

Room.cpp did not require direct changes for the Player integration. Its existing functions already supported the new design because rooms still provide descriptions, actions, and items that the Player can interact with.

LinkedList.h did not need major changes for the new object integration. It still manages the sequence of Room objects in the game. The Player object was added on top of the existing room navigation structure rather than replacing it.

LinkedList.cpp did not require direct changes for the new Player object. It still handles how rooms are stored and traversed in order. The updated game continues to use the linked list as the main room navigation structure.

New Object Contributed

I added the Player object to the game. The Player class stores the player’s name, health, and inventory. This object was integrated into the main game loop so the player can collect items, view status information, and lose health during gameplay.

To integrate the new Player object, I added two new files: Player.h and Player.cpp. I also updated main.cpp so the program now creates a Player at the start of the game and uses that object during room interaction. Two new functions were added to main: pickUpItem() and showPlayerStatus(). These changes made it possible to add inventory and health features, which improved the game beyond simple room-to-room movement.