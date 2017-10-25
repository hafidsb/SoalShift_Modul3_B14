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
int counter = 0;

void * count_word(void *arg);

int main(int argc, char * argu[])
{
    int i=1;
    int err;

    while(i<=argc)//looping membuat thread sebanyak argumen
    {
        err=pthread_create(&(tid[i]),NULL, &count_word, (void *)argu[i]);//membuat thread
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
    FILE *f;
    char y;
    char v[1024];
    int a = 0, b = 0;    
    //int var[111]; // tamppung counter masing2 kata
    //counter++;
    f = fopen("Novel.txt", "r");
    while((y = fget(f)) != EOF)
    {
        if(strstr(v, "ifah")) a++;
    }
    fclose();
}
