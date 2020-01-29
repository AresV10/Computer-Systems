#include <stdio.h>
#include <stdlib.h>

struct Room
{
        char *description;
        struct Item *listOfItems;
        struct Room *up;
        struct Room *down;
        struct Room *west;
        struct Room *east;
        struct Room *north;
        struct Room *south;
        struct Room *freeList;
        int monster;
};

/*
Creates a struct of type room and assignes it the given values.
returns the room.
*/
struct Room *createWorld();

//Creates a struct of type room and assignes it the given values. returns the room.
struct Room *createRoom(char *, struct Item *, struct Room *, struct Room *, struct Room *, struct Room *, struct Room *, struct Room *, int, struct Room *);

//Returns the room to the north of the current room
struct Room *goNorth(struct Room *cur);

//Returns the room to the south of the current room
struct Room *goSouth(struct Room *cur);

//Returns the room to the east of the current room
struct Room *goEast(struct Room *cur);

//Returns the room to the west of the current room
struct Room *goWest(struct Room *cur);

//Returns the room above the current room
struct Room *goUp(struct Room *cur);

//Returns the room below the current room
struct Room *goDown(struct Room *cur);

//Frees the dynamically allocated memory for the given linked list
void destroyWorld(struct Room *head);
