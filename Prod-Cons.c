#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 5

int buffer[SIZE];
int count = 0;

pthread_mutex_t lock;

void* producer(void* arg) {
    for(int i = 0; i < 10; i++) {

        pthread_mutex_lock(&lock);
        if(count < SIZE) {
            buffer[count] = i;
            printf("Producer produced: %d\n", i);
            count++;
        }
        pthread_mutex_unlock(&lock);

        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    for(int i = 0; i < 10; i++) {

        pthread_mutex_lock(&lock);
        if(count > 0) {
            count--;
            printf("Consumer consumed: %d\n", buffer[count]);
        }
        pthread_mutex_unlock(&lock);

        sleep(2);
    }
    return NULL;
}

int main() {
    pthread_t p, c;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    pthread_mutex_destroy(&lock);

    return 0;
}
