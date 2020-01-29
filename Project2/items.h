#include <stdio.h>
#include <stdlib.h>
#include "string.h"

struct Item {
    char *name;
    char *description;
    int num;
    int damage;
    struct Item *next;
    
};

/*
Creates a struct of type item and assignes it the given values.
returns the item.
*/
struct Item *createItem(char *name, char *description, int quantity1, int damage1, struct Item *next);

/*
This function reates a linked list of items by using createItem() multiple times.
returns the head of the linked list of items.
*/
struct Item* createItemList(int,int,int,int,int,int);

/*
Increases the quantity of the given item by x ammount.
recursively goes through the linked list to find the right item to add to.
*/
void itemAdd(struct Item* head, char * name, int x);

/*
Makes the quantity of the given item 0. This is useful when taking items from the room.
Recursively goes through the linked list to find the right item to remove from.
Also it checks if the item has a quantity greater than 0 in the room.
returns 1 if there were no problems in removing the item, and 0 if it didn't work
*/
int itemRemove(struct Item *head, char * name);

//Returns the quantity of an item present in the linked list
int itemQuantity(struct Item* head, char * name);

//Checks if user has a SuperSword, a sword, or no wepon at all based on which the player damage is reutrned
int damageOf(struct Item* head);

//The same as itemRemove except is doesn't make the quantity 0, but it subtracts it by one. Useful in USE fuction
int itemSubtract(struct Item *head, char * name);

//Iterates through the given linked list and prints the items which have a quantity greater than 0
void look(struct Item *curIt);

//Frees the dynamically allocated memory for the given linked list
void purge(struct Item *head);

 