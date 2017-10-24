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
            if(err!=0)//cek error
            {
                printf("\ncan't create thread : [%s]\n",strerror(err));
            }
            else
            {
                printf("\ncreate thread success\n");
            }
            i++;
        }// end thread-maker while
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
   
        if(status_lohan <= 0 || status_lohan > 100 || status_crab <= 0 || status_crab > 100)
        break;
    }// end while
    
    printf("Game over x.x\n"); check = 1;
    
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
        while(check == 0)
        {
          printf("\nlohan_status\n");
          sleep(5);
          status_lohan -= 20;
          if(check == 1) break;
          printf("\n%d\n", status_lohan);          
        }    
    }
    if(pthread_equal(id,tid[1]))
    {
        //ini crab
        while(check == 0)
        {
          printf("\ncrab_status\n");
          sleep(8);
          status_crab -= 20;
          if(check == 1)break;            
          printf("\n%d\n", status_crab); 
        }
    }
    return NULL;
}// end lohan_and_crab
