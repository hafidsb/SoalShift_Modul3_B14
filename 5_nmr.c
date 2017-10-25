#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
/*******************************************************
*compile dengan cara gcc -pthread -o [output] input.c *
*******************************************************/

void *count_word(void *arg)
{
    //printf("cek\n");
    FILE *f;
    char word_search[25]; // ini kata yang dicari
    char word_read[100]; // ini isi file stream yang akan dibaca
    int temp = 0;
    f = fopen("Novel.txt", "r");
    strcpy(word_search, arg);
    //printf("%s\n", word_search);
    while(fscanf(f, "%s", word_read) != EOF)
    {
        if(strstr(word_read, word_search) != NULL) temp++;
    }
    fclose(f);    
    printf("\nJumlah kata %s : %d kata\n", word_search, temp);
    
}

int main(int argc, char *argu[])
{   
    pthread_t tid[argc]; // isinya trit-trit gitu sesuai banyak input
    int i;
    for(i=1; i<=argc; i++)//looping membuat thread sebanyak argumen
    {
        pthread_create(&(tid[i]),NULL, &count_word, (void *)argu[i]);//membuat thread
    }

    for(i=1; i<=argc; i++)// pthread_join sebanyak jml argumen
    {
        pthread_join(tid[i],NULL);
    }
    
    return 0;
}

