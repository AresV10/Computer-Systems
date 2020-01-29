#include "rooms.h"
#include "items.h"

struct Room *createRoom(char *description, struct Item *items, struct Room *north, struct Room *south, struct Room *east, struct Room *west, struct Room *up, struct Room *down, int monster, struct Room *freeList)
{
    struct Room *newReturn = (struct Room *)malloc(sizeof(struct Room));
    newReturn->description = description;
    newReturn->listOfItems = items;
    newReturn->up = up;
    newReturn->down = down;
    newReturn->west = west;
    newReturn->east = east;
    newReturn->north = north;
    newReturn->south = south;
    newReturn->monster = monster;
    newReturn->freeList = freeList;
    return newReturn;
}
struct Room *goNorth(struct Room *cur)
{
    return cur->north;
}
struct Room *goSouth(struct Room *cur)
{
    return cur->south;
}
struct Room *goEast(struct Room *cur)
{
    return cur->east;
}
struct Room *goWest(struct Room *cur)
{
    return cur->west;
}
struct Room *goUp(struct Room *cur)
{
    return cur->up;
}
struct Room *goDown(struct Room *cur)
{
    return cur->down;
}


//The naming sceme for the vaiables is R (the floor they are on) number of room
//SO R2A is the first room of floor 2
struct Room *createWorld()
{
    struct Room *MStart = createRoom("The start room, you can type 'GO _____' to go in that direction, try typing 'GO south' \n", createItemList(0,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);                                                                                                                                                                          // talks about GO function
    struct Room *R1A = createRoom("Good Job, you can follow simple commands, now every room might have some items type 'LOOK' to see what items are in the room. \nYou can then pick them up by typing 'TAKE __________' and drop them by typing 'DROP _______' where the ___ is the name of the item \n", createItemList(0,1,2,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL); // go down and talks about take and drop
    struct Room *R1B = createRoom("Okay so this game has monsters that you CAN kill, so here is one, and you picked a dagger up in the last room, didn't you?\nUse 'LOOK' to first identify the monster then use 'ATTACK' to inflict damage\n", createItemList(0,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 1, NULL);                                                                                                           // explain fight mechanics
    struct Room *R1C = createRoom("Good job, now this game has coins. You can pick these up but who knows what they do? \nIts a text game, did you really think they have an economy here?\n", createItemList(100,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);                                                                                                            // explain coins
    struct Room *R1D = createRoom("And since there are monsters in this game we can't have you dying all the time right? So as in any other game we have health potions. Type 'STASH' to get a list of consumable items and then type 'USE _____' to use the item", createItemList(0,0,3,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);                                        // health potions
    struct Room *R1E = createRoom("Well thats all you need to know, for this game, good luck\nYou're at a cenral chamber with stairs going down and up. You get a feeling that your parents will be dissapointed if you go down just yet", NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);                                                                 // UP or DOWN (hint probably want to go up)

    struct Room *R2A = createRoom("But wait, is that an open safe over there in this room?\n", createItemList(25,0,0,1,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);
    struct Room *R2B = createRoom("Now you realize that they spent all their money on one room as this room is barren.\n", createItemList(5,0,0,1,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);
    struct Room *R2C = createRoom("The room has some furniture in it. You think to yourself that this would have been a good low budget apartment for one to live in.\n", createItemList(30,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 1, NULL);
    struct Room *R2D = createRoom("A room lit only by a candle. There are a lot of shadows in the room.\n", createItemList(13,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 1, NULL);
    struct Room *R2E = createRoom("Seems like a lab of some sort. You find that they were performing electrolysis on some vials.\n", createItemList(5,0,0,3,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);
    struct Room *R2F = createRoom("Good move coming here. Now to explore the floor! Onward!", createItemList(0,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);
    struct Room *R2G = createRoom("Just a regular hallway, or is it?", createItemList(10,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 1, NULL);
    struct Room *R2H = createRoom("Is that a lab Vial storage shelf there?\n", createItemList(13,0,3,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);
    struct Room *R2I = createRoom("Finally a breather, that was some battle huh.\n", createItemList(2,0,1,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);
    struct Room *R2J = createRoom("You're now at a two way junction. You're not sure which way to go, but there is always one thing to do.\n", createItemList(30,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 1, NULL);
    struct Room *R2K = createRoom("This is definitely a hallway.\n", createItemList(2,0,0,1,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);
    struct Room *R2L = createRoom("The room is dark and you feel scared. For good reason I say.\n", createItemList(21,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 1, NULL);
    struct Room *R2M = createRoom("Theres a huge mirror on the wall. You look into it and see a hideous figue. Wait, thats just you. All those monsters you killed, their blood is on you now. Literally.\n", createItemList(1,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);
    struct Room *R2N = createRoom("There is a weird shipping box in the room. You feel a positive energy from the west side.\n", createItemList(15,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 1, NULL);
    struct Room *R2O = createRoom("You feel a positive energy from the east side.\n", createItemList(6,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);

    struct Room *R2P = createRoom("The room is filled with mystical aura. \nIn the corner of your eye you see a glint from an item that seems to be out of its place in location and in time.\nSeems like there is a portal at the top of the room.\n", createItemList(0,0,0,0,0,1), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL); //SPECIAL ROOM

    struct Room *R3A = createRoom("Heal all you want here.\n", createItemList(0,1,4,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL); //Heal Room
    struct Room *R3B = createRoom("So you came down huh? Well let's hope you're ready to deal with this.\n", createItemList(0,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL); //Floor first, 
    struct Room *R3C = createRoom("Its a room with four walls. Oh and yeah it does have a roof, thanks for asing.\n", createItemList(0,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 1, NULL);
    struct Room *R3D = createRoom("Mate, you just go the short end of the stick.\n", createItemList(0,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 3, NULL); // Trap Room
    struct Room *R3E = createRoom("Well Time to gear up and use all your potions now.\n", createItemList(0,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);
    struct Room *R3F = createRoom("Its showtime baby.\n", createItemList(0,0,0,0,0,0), NULL, NULL, NULL, NULL, NULL, NULL, 0, NULL);
    struct Room *R3G = createRoom("Theres a boss in the room. He's ready to kill you.\n", createItemList(0,0,0,0,1,0), NULL, NULL, NULL, NULL, NULL, NULL, 2, NULL); //Boss room
    struct Room *R3H = createRoom("You finished the game congragulations!\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, 16, NULL); // final win room

        //FLOOR 1
        MStart->south = R1A;
        R1A->south = R1B;
        R1B->south = R1C;
        R1C->south = R1D;
        R1D->south = R1E;
        R1E->up = R2F;
        R1E->down = R3B;

        R1B->north = R1A;
        R1C->north = R1B;
        R1D->north = R1C;
        R1E->north = R1D;
        R2F->down = R1E;
        R3B->up = R1E;
    
        //FLOOR 2
        R2A->south = R2B;
        R2B->south = R2C;
        R2C->south = R2F;
        R2F->south = R2K;
        R2K->south = R2N;
        R2E->south = R2J;
        R2D->south = R2I;
        R2I->south = R2M;
        R2L->south = R2O;

        R2B->north = R2A;
        R2C->north = R2B;
        R2F->north = R2C;
        R2K->north = R2F;
        R2N->north = R2K;
        R2J->north = R2E;
        R2I->north = R2D;
        R2M->north = R2I;
        R2O->north = R2L;

        R2F->west = R2E;
        R2E->west = R2D;
        R2K->west = R2J;
        R2J->west = R2I;
        R2M->west = R2L;
        R2H->west = R2G;
        R2G->west = R2F;

        R2N->west = R2P;//sp Room

        R2E->east = R2F;
        R2D->east = R2E;
        R2J->east = R2K;
        R2I->east = R2J;
        R2L->east = R2M;
        R2G->east = R2H;
        R2F->east = R2G;

        R2O->east = R2P; //sp room
        R2P->up = R2F;
        R2P->east = R2N;

        //FLOOR3
        R3B->west = R3A;
        R3C->west = R3B;
        R3E->west = R3C;
        R3F->west = R3E;

        R3A->east = R3B;
        R3B->east = R3C;
        R3C->east = R3E;
        R3E->east = R3F;
        R3F->east = R3G;
        R3G->east = R3H;

        R3C->north = R3D;
        R3D->south = R3C;

        //Free list allocations
        R1A->freeList = R1B;
        R1B->freeList = R1C;
        R1C->freeList = R1D;
        R1D->freeList = R1E;
        R1E->freeList = R2A;
        
        R2A->freeList = R2B;
        R2B->freeList = R2C;
        R2C->freeList = R2D;
        R2D->freeList = R2E;
        R2E->freeList = R2F;
        R2F->freeList = R2G;
        R2G->freeList = R2H;
        R2H->freeList = R2I;
        R2J->freeList = R2J;
        R2K->freeList = R2K;
        R2L->freeList = R2L;
        R2M->freeList = R2M;
        R2N->freeList = R2N;
        R2O->freeList = R2O;
        R2P->freeList = R3A;

        R3A->freeList = R3B;
        R3B->freeList = R3C;
        R3C->freeList = R3D;
        R3D->freeList = R3E;
        R3E->freeList = R3F;
        R3F->freeList = R3G;
        R3G->freeList = R3H;

    
    return MStart;
}

void destroyWorld(struct Room *head){
    
    if (head == NULL)
        return;

    destroyWorld(head->freeList);

    purge(head->listOfItems);
    free(head);
    head=NULL;

}