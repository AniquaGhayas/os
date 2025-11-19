#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5   // number of philosophers

pthread_mutex_t chopstick[N];

void* philosopher(void* num) {
    int id = *(int*)num;

    printf("Philosopher %d is thinking\n", id);
    sleep(1);

    // Pick left chopstick
    pthread_mutex_lock(&chopstick[id]);
    // Pick right chopstick
    pthread_mutex_lock(&chopstick[(id + 1) % N]);

    printf("Philosopher %d is eating\n", id);
    sleep(2);

    // Put down both chopsticks
    pthread_mutex_unlock(&chopstick[id]);
    pthread_mutex_unlock(&chopstick[(id + 1) % N]);

    printf("Philosopher %d finished eating\n", id);
    return NULL;
}

int main() {
    pthread_t ph[N];
    int id[N];

    for (int i = 0; i < N; i++)
        pthread_mutex_init(&chopstick[i], NULL);

    for (int i = 0; i < N; i++) {
        id[i] = i;
        pthread_create(&ph[i], NULL, philosopher, &id[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(ph[i], NULL);

    for (int i = 0; i < N; i++)
        pthread_mutex_destroy(&chopstick[i]);

    return 0;
}
