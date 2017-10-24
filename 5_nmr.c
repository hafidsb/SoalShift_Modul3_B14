#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[111];

int main(void)
{
    int i=0;
    int err, opsi;
    pthread_t crab, lohan; // inisialisasi trit awal

    while(i<2)//looping membuat thread 3x
    {
            // membuat thread ke-i
            //err=pthread_create(&(tid[i]),NULL, &lohan_and_crab, NULL);
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
    printf("Iyey\n");
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);  
    return 0;
}
