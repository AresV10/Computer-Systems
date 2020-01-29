#include <stdio.h>

struct Item;
struct Room;
struct Item* createItem(char *, char *, struct Item *);
struct Room * createRoom(char* , struct Item* ,struct Room *, struct Room *,struct Room *, struct Room *,struct Room *, struct Room *);
char item_name(struct Item *);
char item_description(struct Item *);
struct Item * item_next(struct Item *);
struct Item* item_take(struct Item* ,char *);
void roomExitNorth(struct Room*, struct Room*);


struct Item {
    char *name;
    char *description;
    struct Item *next;
};

struct Room {
        char * description;
        struct Item* listOfItems;
        struct Room *up;
        struct Room *down;
        struct Room *west;
        struct Room *east;
        struct Room *north;
        struct Room *south;
};

struct Item* createItem(char *name, char *description, struct Item *next) {
    struct Item *new_item = (struct Item *) malloc(sizeof(struct Item));
    new_item->name = name;
    new_item->description = description;
    new_item->next = next;
    return new_item;
}

struct Room * createRoom(char* description, struct Item* items,struct Room *north, struct Room *south,struct Room *east, struct Room *west,struct Room *up, struct Room *down){
    struct Room * newReturn = (struct Room *) malloc(sizeof(struct Room));
    newReturn->description = description;
    newReturn->listOfItems = items;
    newReturn->up = up;
    newReturn->down = down;
    newReturn->west = west;
    newReturn->east = east;
    newReturn->north = north;
    newReturn->south = south;
    return newReturn;

}

char item_name(struct Item *item) {
    return item->name;
}

char item_description(struct Item *item) {
    return item->description;
}

struct Item * item_next(struct Item *item) {
    return item->next;
}

struct Item* item_take(struct Item* head,char *item) {
    if(strcmp(head->next->name, item) == 0){
            struct Item* retItem = head->next;
            head->next = NULL;
            retItem->next = NULL;
            return retItem;
    }
    item_take(head->next, item);
}

void roomExitNorth(struct Room* cur, struct Room* diff){
    cur->north = diff;
}


void main() {
struct Item* head = createItem(NULL, NULL, NULL);
    struct Item* items = createItem("bronze key", "a dull bronze key", createItem("rope", "a leather-bound rope", NULL));
    head->next = items;
    struct Item* rope = item_take(items, "rope");
    char * name = rope->name;
    printf("%s",name);
    return;
}