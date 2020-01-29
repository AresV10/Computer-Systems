#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

// A struct for the linked list containing the already seen words from the file
struct wordS
{
  int count;
  struct wordS *next;
  char word[];
};

//Function to compare/add a given word to the list. (increasese count if already present and adds if not)
void wordAdd(char *);

//Function to print the list of words with their frequencies
void printList(struct wordS *);

//Function to free all the allocated memory
void freeList(struct wordS *head);