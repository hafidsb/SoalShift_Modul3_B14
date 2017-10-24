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
int status_crab = 100, status_lohan = 100; // status awal
void * feed_lohan();
void * feed_crab();
void * lohan_and_crab(void *arg);

int main(void)
{
    int i=0;
    int err;
    pthread_t crab, lohan; // inisialisasi trit awal

    while(1)
    {
        while(i<2)//looping membuat thread 3x
        {
            err=pthread_create(&(tid[i]),NULL, &lohan_and_crab, NULL);//membuat thread
            if(err!=0)//cek error
            {
                printf("\ncan't create thread : [%s]\n",strerror(err));
            }
            else
            {
                printf("\ncreate thread success\n");
            }
            i++;
        }   
        if(status_lohan <= 0 || status_lohan > 100 || status_crab <= 0 || status_crab > 100)
        break;
    }// end while
    
    printf("Game over x.x\n");
    
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);  

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
    pthread_t id = pthread_self();
 
    if(pthread_equal(id,tid[0]))
    {
        //ini lohan yaah
        while(1)
        {
          printf("astaghfirullah\n");
          sleep(2);
          status_lohan -= 10;
          if(status_lohan<=0 || status_lohan>100 || status_crab<=0 || status_crab>100) break;
          printf("%d\n", status_lohan);          
        }    
    }
    if(pthread_equal(id,tid[1]))
    {
        //ini crab
        while(1)
        {
          printf("subhanallah\n");
          sleep(3);
          status_crab -= 20;
          if(status_lohan<=0 || status_lohan>100 || status_crab<=0 || status_crab>100)break;            
          printf("%d\n", status_crab); 
        }
    }
    /*if(pthread_equal(id,tid[2]))
    {
        // feed
        int opsi;
        printf("status lohan = %d  ||  status crab = %d\n", status_lohan, status_crab);
        printf("Opsi:\n");
        printf("1. Feed lohan\n");
        printf("2. Feed crab\n");
        printf("Input a number(1 or 2)> ");
        scanf("%d", &opsi);
        if(opsi == 1)
        feed_lohan();
        else if(opsi == 2)
        feed_crab();
        else{ 
        printf("Number invalid, try again!");
        sleep(4);
        }
        system("clear");
    } */

    return NULL;
}// end lohan_and_crab
