Adventure game
==========================================================================================================================================================================================
ABOUT GAME:

This program is a Text based game where the user controls an avatar, through the game. The game starts on a floor with directions and teaches the user about the mechanics. 

It teaches the user about the LOOK, GO ____, TAKE ____, USE____, DROP____, STASH, ATTACK functions.

    LOOK gives a list of items in the room, also makes any hidden monster visible

    GO ____ allows the player to move in the specified direction

    TAKE ____ allows the player to pick up items in the room

    USE ____ allows the player to use the item from their stash 

    DROP ____ allows the player to drop items from stash

    STASH allows the user to view the items they are holding

    ATTACK allows the user to attack any unhidden monsters in the room

After that it splits into two floors

The upper floor is where the players and find the duplicate item. 

    USE dup ____ allows to either power up an item or duplicate the item

From the room they found the item they can choose to be teleported to the first room of this floor.

From there they can go to the bottom floor, the boss floor. At the last but one room there is a boss, who is a normal monster but, with higher stats. The boss room contains the key.
And only one you pick the key up you can access the win room.
==========================================================================================================================================================================================
VIDEO LINK:

https://youtu.be/QUJ4qdqPDos
==========================================================================================================================================================================================
ABOUT CODE:

The game works based on rooms. Each room either has an item or it doesn't or it has a monster in it or not. This could be changed easily into a probability, where there is a chance of a
monster spawning in the rooms.

There is a linked list of rooms and each room has an item linked list as well. The item linked list keeps track of the items and their quantities.
==========================================================================================================================================================================================
ABOUT FUNCTIONS:

FUNCTIONS in item.h

    struct Item *createItem(char *name, char *description, int quantity, int damage, struct Item *next);

        Creates a struct of type item and assignes it the given values.
        returns the item.

    struct Item* createItemList(int coins, int sword, int potion, int speed, int key, int dup);

        This function reates a linked list of items by using createItem() multiple times.
        returns the head of the linked list of items.

    void itemAdd(struct Item* head, char * name, int x);

        Increases the quantity of the given item by x ammount.
        recursively goes through the linked list to find the right item to add to.

    int itemRemove(struct Item *head, char * name);

        Makes the quantity of the given item 0. This is useful when taking items from the room.
        Recursively goes through the linked list to find the right item to remove from.
        Also it checks if the item has a quantity greater than 0 in the room.
        returns 1 if there were no problems in removing the item, and 0 if it didn't work

    int itemQuantity(struct Item* head, char * name);

        Returns the quantity of an item present in the linked list

    int damageOf(struct Item* head);

        Checks if user has a SuperSword, a sword, or no wepon at all based on which the player damage is reutrned

    int itemSubtract(struct Item *head, char * name);

        The same as itemRemove except is doesn't make the quantity 0, but it subtracts it by one. Useful in USE fuction

    void look(struct Item *curIt);

        Iterates through the given linked list and prints the items which have a quantity greater than 0

    void purge(struct Item *head);

        Frees the dynamically allocated memory for the given linked list

FUNCTIONS in rooms.h

    struct Room *createRoom(char *description, struct Item *listOfItems, struct Room *north, struct Room *south, struct Room *east, struct Room *west, struct Room *up, struct Room *down, int monster, struct Room *freeList);

        Creates a struct of type room and assignes it the given values.
        returns the room.

    struct Room *createWorld();

        This function reates a linked list of rooms by using createRoom() multiple times.
        Returns the head of the linked list of items.

    struct Room *goNorth(struct Room *cur);

        Returns the room to the north of the current room

    struct Room *goSouth(struct Room *cur);

        Returns the room to the south of the current room

    struct Room *goEast(struct Room *cur);

        Returns the room to the east of the current room

    struct Room *goWest(struct Room *cur);

        Returns the room to the west of the current room

    struct Room *goUp(struct Room *cur);

        Returns the room above the current room

    struct Room *goDown(struct Room *cur);

        Returns the room below the current room

    void destroyWorld(struct Room *head);

        Frees the dynamically allocated memory for the given linked list

FUNCTIONS in adventure.c

    void attackPlayer(struct Monster *mon, struct Player *mc)

        Subtracts monater damage from player health

    void itemUse(struct Player *mc, char *name)

        Based on the given input, it applies the effects of the items to the player 


==========================================================================================================================================================================================
