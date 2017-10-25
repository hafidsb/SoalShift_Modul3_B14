#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid;
int angkanya;

void *hitungfaktorial(void *arg);

int main(int argc, char const *argv[])
{
    int banyaknya= argc - 1;
    int i;
    for (i= 1; i<= banyaknya; i++)
    {
        angkanya= atoi(argv[i]);
        int cek= pthread_create(&tid, NULL, hitungfaktorial, NULL);
        if(!cek)
        {
            printf("Gagal membuat thread, return value = %d\n", cek);
            exit(EXIT_FAILURE);
        }
        pthread_join(tid, NULL);
    }
    return 0;
}


