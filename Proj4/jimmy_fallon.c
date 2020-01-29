#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_THREADS 10

volatile int cnt = 0;
volatile int next_id = 0;
int NumCalls = 0;
sem_t connected_lock;
sem_t operators;

void *phonecall(void *);

int main(int argc, char **argv)
{
    int called = 0;
    if(argc>1){
        NumCalls = atoi(argv[1]);
        called = NumCalls;
        if(NumCalls > 240)
            NumCalls = 240;

    }
    else
        NumCalls = MAX_THREADS;

    pthread_t tid[NumCalls];
    //creating all the threads
    sem_init(&connected_lock, 0, 1);
    sem_init(&operators, 0, 3);

    for (int i = 0; i < NumCalls; i++)
    {
        pthread_create(&tid[i], NULL, phonecall, (void *)i);
    }

    //joining all the threads
    for (int i = 0; i < NumCalls; i++)
    {
        pthread_join(tid[i], NULL);
    }

    printf("Sold %u tickets \n", NumCalls);
    return EXIT_SUCCESS;
}

void *phonecall(void *vargp)
{
    //Local variable to name each thread
    int id = ++next_id;
    static int NUM_OPERATORS = 3;
    static int NUM_LINES = 5;
    static int connected = 0; // Callers that are connected
    int bol = 1;

    // critical section 1 - checking if lines are open
    while(bol){
        sem_trywait(&connected_lock);
        if (connected == NUM_LINES)
        {
            printf("Caller [%u] Attempted to Call.\n", id);
            printf("Caller [%u] called a busy line. Ending call. \n\n", id);
            sleep(3);
            // if no availiable lines, end call and try calling again. therefore starts from line check semaphore again.
        }
        else if (connected < NUM_LINES)
        {
            printf("Caller [%u] Attempted to Call.\n", id);
            printf("Caller [%u] has avaliable line, call connected.\n", id);
            connected++; //increment connected as call is now connected
            bol = 0;
        }

        sem_post(&connected_lock);
    }

    sem_trywait(&operators);
    //critical section 2 - checking for free operators
    printf("Caller [%u] Your order is being taken by an operator\n\n", id);
    sleep(3);
    printf("Caller [%u] Your order has been taken\n", id);
    printf("Caller [%u] Your call has ended\n\n", id);
    connected--; //decrement connected as call is ending 
    sem_post(&operators);

    return NULL;
}
