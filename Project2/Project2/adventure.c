#include "rooms.h"
#include "items.h"
#include "string.h"

int base = 100;
struct Player
{
	int health;
	int speed;
	struct Item *PlayerItemStash;
};

struct Monster
{
	int health;
	int speed;
	int damage;
	int spotted;
};

//Subtracts monater damage from player health
void attackPlayer(struct Monster *mon, struct Player *mc)
{
	mc->health -= mon->damage;
}

//Based on the given input, it applies the effects of the items to the player 
void itemUse(struct Player *mc, char *name)
{
	if (strcmp(name, "potion") == 0)
	{
		if (mc->health == base)
		{
			printf("You're already at max health.\n");
			itemAdd(mc->PlayerItemStash, "potion", 1);
			return;
		}
		if (mc->health >= (base - 30))
			mc->health = base;
		else
		{
			mc->health += 30;
		}

		printf("Added 20 HP to player. Current HP is %i.\n", mc->health);
	}
	else if (strcmp(name, "speed") == 0)
	{
		mc->speed += 10;
		printf("Added 10 points to speed. Your current speed is %i.\n", mc->speed);
	}
	else if (strcmp(name, "dup") == 0)
	{
		printf("You found the secret Item!! You can use this to Power Up/Duplicate your items. Type the name of the item to Duplicate or exit to continue\n");
		char inputA[15];
		scanf("%s", inputA);
		if (strcmp(inputA, "exit") == 0)
		{
			return;
		}
		else if (strcmp(inputA, "key") == 0)
		{
			itemAdd(mc->PlayerItemStash, "key", 1);
			return;
		}
		else if (strcmp(inputA, "potion") == 0)
		{
			itemAdd(mc->PlayerItemStash, "SuperPotion", 1);
			return;
		}
		else if (strcmp(inputA, "speed") == 0)
		{
			itemAdd(mc->PlayerItemStash, "SuperSpeed", 1);
			return;
		}
		else if (strcmp(inputA, "sword") == 0)
		{
			itemAdd(mc->PlayerItemStash, "SuperSword", 1);
			return;
		}
	}
	else if (strcmp(name, "SuperPotion") == 0)
	{
		base = 200;
		mc->health = 200;
		printf("You used the miracle of life. Current HP is refilled and increased to 200.\n");
	}
	else if (strcmp(name, "SuperSpeed") == 0)
	{
		mc->speed = 200;
		printf("You now feel the power of flash coursing through you. Your speed now is 200");
	}
	return;
}

int main()
{
	struct Player *mainPlayer = (struct Player *)malloc(sizeof(struct Player));

	mainPlayer->health = 100;
	mainPlayer->speed = 50;
	mainPlayer->PlayerItemStash = NULL;

	struct Room *cur = createWorld();
	struct Room *hold = cur;
	mainPlayer->PlayerItemStash = createItemList(0, 0, 0, 0, 0, 0);
	printf("%s", cur->description);

	struct Monster *monsterSp = NULL;

	while (mainPlayer->health > 0)
	{
		if (cur->monster == 16)
		{
			printf("\n///////////////////////////////////////////////////////////////////////////////////\n YOU WON THE GAME!!!!!!\n///////////////////////////////////////////////////////////////////////////////////\n");
			return 0;
		}
		printf("\n///////////////////////////////////////////////////////////////////////////////////\n HP: %i | Speed: %i\n///////////////////////////////////////////////////////////////////////////////////\n\n", mainPlayer->health, mainPlayer->speed);
		if (cur->monster == 1)
		{
			monsterSp = (struct Monster *)malloc(sizeof(struct Monster));
			monsterSp->damage = 20;
			monsterSp->health = 40;
			monsterSp->speed = 60;
			monsterSp->spotted = 0;
			cur->monster = 0;
		}
		else if (cur->monster == 2)
		{
			printf("Its the boss fight, you've already spotted him!\n");
			monsterSp = (struct Monster *)malloc(sizeof(struct Monster));
			monsterSp->damage = 40;
			monsterSp->health = 80;
			monsterSp->speed = 60;
			monsterSp->spotted = 1;
			cur->monster = 0;
		}
		// take input
		char action[30];
		char subAction[30];

		scanf("%s", action);

		//based on input do the thing
		if (strcmp(action, "GO") == 0)
		{
			scanf("%s", subAction);

			if (monsterSp != NULL)
			{
				printf("You have been attacked by a monster!\n");
				if (monsterSp->speed > mainPlayer->speed)
				{
					attackPlayer(monsterSp, mainPlayer);
					printf("Monster attacked you. You were startled!\n");
				}
				continue;
			}

			if (strcmp(subAction, "north") == 0)
			{
				if (goNorth(cur) == NULL)
				{
					printf("There are no EXITS in this direction, try another direction.\n");
					continue;
				}
				printf("%s\n", cur->north->description);
				cur = goNorth(cur);
				continue;
			}
			else if (strcmp(subAction, "south") == 0)
			{
				if (goSouth(cur) == NULL)
				{
					printf("There are no EXITS in this direction, try another direction.\n");
					continue;
				}
				printf("%s\n", cur->south->description);
				cur = goSouth(cur);
				continue;
			}
			else if (strcmp(subAction, "east") == 0)
			{
				if (goEast(cur) == NULL)
				{
					printf("There are no EXITS in this direction, try another direction.\n");
					continue;
				}
				if (cur->east->monster == 16)
				{
					if ((mainPlayer->PlayerItemStash->next->next->next->next->next->next->next)->num == 1)
					{
						printf("%s\n", cur->east->description);
						cur = goEast(cur);
						continue;
					}
					else
					{
						printf("You need a key to Proceed");
						continue;
					}
				}
				printf("%s\n", cur->east->description);
				cur = goEast(cur);
				continue;
			}
			else if (strcmp(subAction, "west") == 0)
			{
				if (goWest(cur) == NULL)
				{
					printf("There are no EXITS in this direction, try another direction.\n");
					continue;
				}
				printf("%s\n", cur->west->description);
				cur = goWest(cur);
				continue;
			}
			else if (strcmp(subAction, "up") == 0)
			{
				if (goUp(cur) == NULL)
				{
					printf("There are no EXITS in this direction, try another direction.\n");
					continue;
				}
				printf("%s\n", cur->up->description);
				cur = goUp(cur);
				continue;
			}
			else if (strcmp(subAction, "down") == 0)
			{
				if (goDown(cur) == NULL)
				{
					printf("There are no EXITS in this direction, try another direction.\n");
					continue;
				}
				printf("%s\n", cur->down->description);
				cur = goDown(cur);
				continue;
			}
			else
			{
				printf("Enter a valid direction.\n");
				continue;
			}
		}
		else if (strcmp(action, "LOOK") == 0)
		{
			look(cur->listOfItems);
			if (monsterSp != NULL)
			{
				printf("You also see the shadow of a monster hiding in the corner of the room, eagerly waiting to attack you\n");
				monsterSp->spotted = 1;
			}
		}
		else if (strcmp(action, "TAKE") == 0)
		{
			scanf("%s", subAction);

			if (subAction == NULL)
			{
				printf("Enter an item for TAKE");
			}

			int x = itemRemove(cur->listOfItems, subAction);
			if (x > 0)
			{
				itemAdd(mainPlayer->PlayerItemStash, subAction, x);
				printf("You obtained %i %ss\n", x, subAction);
			}
		}
		else if (strcmp(action, "ATTACK") == 0)
		{

			if (monsterSp != NULL)
			{
				if (monsterSp->speed > mainPlayer->speed)
				{
					attackPlayer(monsterSp, mainPlayer);
					printf("Monster attacked you and did damage.\n");
				}
				if (monsterSp->spotted == 1)
				{
					if (monsterSp->health > 0)
					{
						int y = (mainPlayer->speed) / (monsterSp->speed);
						if (y == 0)
						{
							y = 1;
						}
						monsterSp->health -= (damageOf(mainPlayer->PlayerItemStash) * (y));
						if (monsterSp->health < 0)
						{
							monsterSp->health = 0;
						}
						if (damageOf(mainPlayer->PlayerItemStash) == 0)
						{
							printf("You have no item. You do 0 damage. The monster's remaining health is %i\n", monsterSp->health);
						}
						else
						{
							printf("Successfully attacked the monster. Its remaining health is %i\n", monsterSp->health);
						}

						if (monsterSp->health <= 0)
						{
							free(monsterSp);
							monsterSp = NULL;
							printf("You beat the monster");
							continue;
						}
					}
				}
				else
				{
					printf("The Monster parries you attack as it was prepared and it attacks you");
					attackPlayer(monsterSp, mainPlayer);
				}
			}
			else
			{
				printf("Are you trying to attack thin air? Stop wasting everyone's time\n");
			}
		}
		else if (strcmp(action, "DROP") == 0)
		{
			scanf("%s", subAction);

			if (subAction == NULL)
			{
				printf("Enter a item name");
			}

			int x = itemRemove(mainPlayer->PlayerItemStash, subAction);
			itemAdd(cur->listOfItems, subAction, x);
		}
		else if (strcmp(action, "USE") == 0)
		{
			scanf("%s", subAction);

			if (subAction == NULL)
			{
				printf("Enter a valid item to use.\n");
			}

			int x = itemSubtract(mainPlayer->PlayerItemStash, subAction);
			if (x)
				itemUse(mainPlayer, subAction);
		}
		else if (strcmp(action, "STASH") == 0)
		{
			look(mainPlayer->PlayerItemStash);
		}
		else{
			printf("Enter a valid command.\n");
		}

		if (monsterSp != NULL)
		{
			if (monsterSp->spotted == 0)
			{
				monsterSp->spotted = 1;
				continue;
			}
		}
	}
	printf("\n///////////////////////////////////////////////////////////////////////////////////\nHP: 0 \nYOU DIED\n///////////////////////////////////////////////////////////////////////////////////\n");

	destroyWorld(hold);
	purge(mainPlayer->PlayerItemStash);

	return 0;
}