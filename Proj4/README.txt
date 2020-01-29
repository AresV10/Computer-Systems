Jimmy Fallon
==========================================================================================================================================================================================
ABOUT Program:

This program inputs the number of callers for a ticket purchasing simulator for the Jimmy Fallon show
==========================================================================================================================================================================================
VIDEO LINK:

https://youtu.be/rQuD0Z6bkhg
==========================================================================================================================================================================================
ABOUT CODE:

The program uses semaphores to make sure that certain parts of memory are protected and not all the processes can modify these part of memory at any point in time.
Thus it being a sense of synchronization between processes.

==========================================================================================================================================================================================
ABOUT FUNCTIONS:

FUNCTIONS in jimmy_falon.c

    int main(int argc, char **argv)

        Main function that contains the creation of multiple threads and their joining

    void *phonecall(void *vargp)

        Thread function that updates the semaphores and checks if there are open operators and open lines.

==========================================================================================================================================================================================
