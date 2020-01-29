Word Freak
==========================================================================================================================================================================================
ABOUT Program:

This program inputs a text file and parses through it and counts the frequence of the words
==========================================================================================================================================================================================
VIDEO LINK:

https://youtu.be/paHELlrjGTA
==========================================================================================================================================================================================
ABOUT CODE:

The program uses certain system calls to open and read the file it also uses dynamic memory allocation for the linked list to store the words that have been parsed through

==========================================================================================================================================================================================
ABOUT FUNCTIONS:

FUNCTIONS in word.h

    void wordAdd(char *);

        Function to compare/add a given word to the list. (increasese count if already present and adds if not)

    void printList(struct wordS *);

        Function to print the list of words with their frequencies

    void freeList(struct wordS *head);

        Function to free all the allocated memory


==========================================================================================================================================================================================
