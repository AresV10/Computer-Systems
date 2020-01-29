#include "word.h"

char f[] = " ";
char q[] = "";
struct wordS *head; //head for the linked list

int main(int argc, char *argv[])
{
  char *eV;
  int file;
  if (argc == 1)
  {
    eV = getenv("WORD_FREAK");

    if (eV == NULL)
    {
      file = 0;
    }
    else
      file = open(eV, O_RDONLY);
  }
  else
  {
    file = open(argv[1], O_RDONLY);
  }

  //allocating memory to buffers and head of linked list
  char *add = (char *)calloc(20, sizeof(char));
  char *data = (char *)calloc(1, sizeof(char));
  head = (struct wordS *)malloc(sizeof(struct wordS) + sizeof(char) + 1);
  //iniitlaizing link list head to arbitrary values for case checking
  head->count = 0;
  head->next = NULL;
  strcpy(head->word, f);

  int numBytes;

  do
  {
    numBytes = read(file, data, 1);
    if (isalpha(data[0]))
    { // if char is an alphabet , add to buffer

      strcat(add, data);
    }
    else
    { //else break the buffer add to linked list, continue.
      wordAdd(add);
      free(add);
      add = (char *)calloc(20, sizeof(char));
    }
  } while (numBytes >= 1);

  close(3); //closes opened file

  printList(head); //prints the linked list

  freeList(head); //frees memory
}

void wordAdd(char *word)
{

  if (strcmp(word, q) == 0) //word is null don't add
  {
    return;
  }
  if (strcmp(head->word, f) == 0) //if it is an axception case (1st word) add word to head, continue.
  {
    head = (struct wordS *)malloc(sizeof(struct wordS) + sizeof(char) * strlen(word) + 1);
    strcpy(head->word, word);
    head->count = 1;
    head->next = NULL;
    return;
  }
  struct wordS *cur = head;
  while (cur != NULL) //iterate through list
  {
    if (strcmp(cur->word, word) == 0) //if matches, increase count
    {
      cur->count++;
      break;
    }
    else if (cur->next == NULL) // else create new node and add to list
    {
      struct wordS *temp = (struct wordS *)malloc(sizeof(struct wordS) + sizeof(char) * strlen(word) + 1);
      cur->next = temp;
      temp->next = NULL;
      temp->count = 1;
      strcpy(temp->word, word);
      break;
    }
    cur = cur->next;
  }
}

void printList(struct wordS *head)
{
  struct wordS *cur = head;
  printf("\n");
  while (cur != NULL)
  {
    printf("\n");
    printf("%s", cur->word);
    printf(" %i", cur->count);

    cur = cur->next;
  }
  printf("\n");
}

void freeList(struct wordS *head)
{
  if (head != NULL)
  {
    freeList(head->next);
    free(head);
  }
  return;
}
