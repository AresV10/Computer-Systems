#include "items.h"

struct Item *createItem(char *name, char *description, int quantity1, int damage1, struct Item *next)
{
    struct Item *newItem = (struct Item *)malloc(sizeof(struct Item));
    newItem->name = name;
    newItem->description = description;
    newItem->num = quantity1;
    newItem->damage = damage1;
    newItem->next = next;

    return newItem;
}

struct Item *createItemList(int a, int b, int c, int d, int e, int f)
{

    struct Item *coins = createItem("coins", "Big Stonks (coins)\n", 100, 0, NULL);
    struct Item *sword = createItem("sword", "A rusty sword, might be useful to nail a test (sword)\n", 1, 10, NULL);
    struct Item *potion = createItem("potion", "So heal me maybe (potion)\n", 1, 0, NULL);
    struct Item *speed = createItem("speed", "Speed, I am speed (speed)\n", 1, 0, NULL);
    struct Item *key = createItem("key", "A golden key (key)\n", 1, 0, NULL);
    struct Item *dup = createItem("dup", "A SUPER magical item that can either power up an item to do wonderful things or duplicate an item (dup)\n", 1, 0, NULL);

    struct Item *superSword = createItem("SuperSword", "Sharp enough to cut you Student Debt in half (SuperSword)\n", 0, 25, NULL);
    struct Item *superPotion = createItem("SuperPotion", "I don't know, drink this to become jesus maybe? (SuperPotion)\n", 0, 0, NULL);
    struct Item *superSpeed = createItem("SuperSpeed", "Im fast as fondue BOI (SuperSpeed)\n", 0, 0, NULL);

    coins->next = sword;
    sword->next = superSword;
    superSword->next = potion;
    potion->next = superPotion;
    superPotion->next = speed;
    speed->next = superSpeed;
    superSpeed->next = key;
    key->next = dup;

    coins->num = a;
    sword->num = b;
    potion->num = c;
    speed->num = d;
    key->num = e;
    dup->num = f;

    return coins;
}

void itemAdd(struct Item *head, char *name, int x)
{

    struct Item *tempa;

    if (head == NULL)
    {
        printf("ERROR");
        return;
    }

    if (strcmp(head->name, name) == 0)
    {
        head->num = head->num + x;
        return;
    }
    else
    {
        tempa = head->next;
    }
    itemAdd(tempa, name, x);
}

int itemRemove(struct Item *head, char *name)
{

    struct Item *tempa;

    if (head == NULL)
    {
        printf("Please enter a valid item\n");
        return 0;
    }

    if (strcmp(head->name, name) == 0)
    {
        if (head->num > 0)
        {
            int temp = head->num;
            head->num = 0;
            return temp;
        }
        else
        {
            printf("You don't have any more of these items.\n");
            return 0;
        }
    }
    else
    {
        tempa = head->next;
    }

    itemRemove(tempa, name);
}

int itemSubtract(struct Item *head, char *name)
{

    struct Item *tempa;

    if (head == NULL)
    {
        printf("Please enter a valid item\n");
        return 0;
    }

    if (strcmp(head->name, name) == 0)
    {
        if (head->num > 0)
        {
            head->num = head->num - 1;
            return 1;
        }
        else
        {
            printf("You don't have any more of these items.\n");
            return 0;
        }
    }
    else
    {
        tempa = head->next;
    }

    itemSubtract(tempa, name);
}

int itemQuantity(struct Item *head, char *name)
{

    struct Item *tempa;

    if (head == NULL)
    {
        printf("ERROR");
        return 0;
    }

    if (strcmp(head->name, name) == 0)
    {
        return head->num;
    }
    else
    {
        tempa = head->next;
    }

    itemQuantity(tempa, name);
}

int damageOf(struct Item *head)
{
    if ((head->next->next)->num >= 1)
    {
        return 100;
    }
    else if ((head->next)->num >= 1)
    {
        return 20;
    }
    else
    {
        return 0;
    }
}

void look(struct Item *curIt)
{

    printf("There is/are\n\n");
    int x = 0;
    struct Item *temp = (struct Item *)malloc(sizeof(struct Item));
    temp = curIt;
    while (temp != NULL)
    {
        if (temp->num > 0)
        {
            printf("%i %s\n", temp->num, temp->description);
            x++;
        }
        temp = temp->next;
    }
    if (x == 0)
    {
        printf("Nothing here.\n\n");
    }
    free(temp);
    temp = NULL;
    return;
}

void purge(struct Item *head)
{
    if (head == NULL)
        return;

    purge(head->next);

    free(head);
    head = NULL;
}
