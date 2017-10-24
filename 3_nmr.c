#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[2];
int status_crab = status_lohan = 100; // status awal
void * feed_lohan();
void * feed_crab();

int main(void)
{
    int i=0;
    int err;
    pthread_t crab, lohan; // inisialisasi trit awal

    while(i<2)//looping membuat thread 2x
    {
        err=pthread_create(&(tid[i]),NULL,NULL,NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]",strerror(err));
        }
        else
        {
            printf("\n create thread success");
        }
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}

void * feed_lohan()
{
    status_lohan += 10;
}

void * feed_crab()
{
    status_crab += 10;
}
