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
void * lohan_and_crab(void *arg);

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

    while(status_lohan > 0 && status_lohan <= 100 && status_crab > 0 && status_crab <= 100)
    {
        sdsd    
    }

    return 0;
} // end main()

void * feed_lohan()
{
    status_lohan += 10;
}

void * feed_crab()
{
    status_crab += 10;
}

void * lohan_and_crab(void *arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();
 
    if(pthread_equal(id,tid[0]))
    {
        //ini lohan yaah
    }
    else if(pthread_equal(id,tid[1]))
    {
        //ini crab
    }
}// end lohan_and_crab
