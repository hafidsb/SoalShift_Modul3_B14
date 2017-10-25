#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

pthread_t tid[111];//inisialisasi array untuk menampung thread 
char  word[25]; // arr yg tampung tiap kata

void * count_word(void *arg);

int main(int argc, char ** argu)
{
    int i=1;
    int err;

    while(i<=argc)//looping membuat thread sebanyak argumen
    {
        strcpy(word, argu[i]);
        err=pthread_create(&(tid[i]),NULL, &count_word, NULL);//membuat thread
        if(err!=0)//cek error
        {
            printf("\n can't create thread : [%s]\n",strerror(err));
        }
        else
        {
            printf("\n create thread success\n");
        }
        i++;
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    return 0;
}

void * count_word(void *arg)
{
    pthread_t id = pthread_self();
    
    if(pthread_equal(id,tid[1]))
    {
        printf("%s 1\n", word);    
    }
    
    if(pthread_equal(id,tid[2]))
    {
        printf("%s 2\n", word);    
    }
}
