#include <pthread.h>
#include <stdio.h>

void *count(void *arg) {
    char* name = (char*)arg;
    for (int i = 0; i < 5; i++) {
        printf("%s: %i\n", name, i);
    }
    return NULL;
}

int main(void) {

    pthread_t t1;
    pthread_t t2;

    printf("Launching threads\n");

    pthread_create(&t1, NULL, count, "thread 1");
    pthread_create(&t2, NULL, count, "thread 2");

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Threads Complete!\n");
}