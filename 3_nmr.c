#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

int check = 0;
pthread_t tid[2];
int status_crab = 100, status_lohan = 100; // status awal
void * feed_lohan();
void * feed_crab();
void * lohan_and_crab(void *arg);

int main(void)
{
    int i=0;
    int err, opsi;
    pthread_t crab, lohan; // inisialisasi trit awal

    while(1)
    {
        while(i<2)//looping membuat thread 3x
        {
            err=pthread_create(&(tid[i]),NULL, &lohan_and_crab, NULL);//membuat thread
            /*if(err!=0)//cek error
            {
                printf("\ncan't create thread : [%s]\n",strerror(err));
            }
            else
            {
                printf("\ncreate thread success\n");
            }*/
            i++;
        }// end thread-maker while
        printf("Status lohan = %d  ||  Status crab = %d\n", status_lohan, status_crab);
        printf("Opsi:\n");
        printf("1. Feed lohan\n");
        printf("2. Feed crab\n");
        printf("Input a number(1 or 2)> ");
        scanf("%d", &opsi);
        if(opsi == 1)
        {
            feed_lohan();
            system("clear");
        }

        else if(opsi == 2)
        {
            feed_crab();
            system("clear");
        }

        else printf("Number invalid, try again!\n\n");
        
        if(status_lohan <= 0 || status_lohan > 100 || status_crab <= 0 || status_crab > 100)
        break;
    }// end while
    
    printf("*Boop~* Game over! x.x\n"); check = 1;
    printf("Waiting remaining threads to finish executing ..\n");
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);  

    printf("... Exit complete!\n");
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
        while(check == 0)
        {
          sleep(10);
          if(check == 1) break;
          status_lohan -= 15;
          printf("\nlohan loses 15 HP || Status lohan = %d\n", status_lohan);
          //printf("\nStatus Lohan = %d\n", status_lohan);
          if(check == 1) break;         
        }    
    }
    if(pthread_equal(id,tid[1]))
    {
        //ini crab
        while(check == 0)
        {
          sleep(20);
          if(check == 1) break;
          status_crab -= 10;
          printf("\ncrab loses 10 HP || Status lohan = %d\n", status_crab);
          //printf("\nStatus Crab = %d\n", status_crab);
          if(check == 1)break;             
        }
    }
    return NULL;
}// end lohan_and_crab
