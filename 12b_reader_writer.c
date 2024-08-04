#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t wrt;
pthread_mutex_t mutex;
int cnt = 1;
int numreader = 0;

void *writer(void *wno)
{   
    sem_wait(&wrt);
  //sem_wait(&sem_name); If the value of the semaphore is negative, the calling process blocks; 
    cnt = cnt*2;
    printf("Writer %d modified cnt to %d\n",(*((int *)wno)),cnt);
    sem_post(&wrt);
  //sem_post(&sem_name); It increments the value of the semaphore and wakes up a blocked process waiting on the semaphore, if any.

}
void *reader(void *rno)
{   
    // Reader acquire the lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader++;
    if(numreader == 1) 
    {
        sem_wait(&wrt); // If this id the first reader, then it will block the writer
    }
    pthread_mutex_unlock(&mutex);
    // Reading Section
    printf("Reader %d: read cnt as %d\n",*((int *)rno),cnt);

    // Reader acquire the lock before modifying numreader
    pthread_mutex_lock(&mutex);
    numreader--;
    if(numreader == 0) 
    {
        sem_post(&wrt); // If this is the last reader, it will wake up the writer.
    }
    pthread_mutex_unlock(&mutex);
}

int main()
{   

    pthread_t read[3],write[3];
    pthread_mutex_init(&mutex, NULL);
//initialize a mutex to its default value
    sem_init(&wrt,0,1);
//sem_init() function initializes an unnamed semaphore and sets its initial value. Syntax: sem_init(sem_t *sem, int pshared, unsigned int value); sem ---> points to a semaphore object to initialize; pshared ---> A value of zero indicates that the semaphore will be used only by threads within the current process. A nonzero value indicates that the semaphore may be used by threads from other processes; value ---> used to initialize the value of the semaphore
    int a[3] = {1,2,3}; //Just used for numbering the reader and writer

    for(int i = 0; i < 3; i++) {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
      //pthread_create(&tid, &attr, threadfun, args);
    }
    for(int i = 0; i < 3; i++) {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }

    for(int i = 0; i < 3; i++) {
        pthread_join(read[i], NULL);
    }
    for(int i = 0; i < 3; i++) {
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
//pthread_mutex_destroy() function destroys the mutex object referenced by mutex; 
    sem_destroy(&wrt);
//int sem_destroy(sem_t *sem)-->destroys the semaphore; no threads should be waiting on the semaphore if its destruction is to succeed.
    return 0;
  }
    

