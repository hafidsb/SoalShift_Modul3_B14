#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t Board1, Board2;

int gameplay=1;
int indekP1= 0, indekP2=1;
int board[2][16];
int play;
int nilai[2];

void *CekSelesai(void *argv)
{
	int i, ranjau, id = *((int *)argv);
	while (1)
	{
		ranjau = 0;
		if(nilai[0]==10 || nilai[1]==10) break;		
		for (i= 0; i< 16; i++){
			if (board[id][i] == 1)	ranjau++;
		}
		if(ranjau==16) break;
	}
	//Tampilkan pemenang
	if(nilai[0] > nilai[1])
	{
		printf("\nPlayer1 Win!\n");
	}
	else if(nilai[0] < nilai[1])
	{
		printf("\nPlayer2 Win!\n");
	}
	else printf("\nGame Draw\n");
	gameplay= 0;
	
	return NULL;
}

void *PasangRanjau(void *p_id)

void *TebakRanjau(void *p_id)

int main(){
	//inisialisasi board
	play= 0;
	nilai[0]= 0;
	nilai[1]= 0;
	memset(board, 0, sizeof board);

	int a= pthread_create(&Board1, NULL, &CekSelesai, (void *)&indekP1);
	if(a!=0)
        {
            printf("Gagal membuat thread, return value = %d\n", cek);
            exit(EXIT_FAILURE);
        }
	int b= pthread_create(&Board2, NULL, &CekSelesai, (void *)&indekP2);
	if(b!=0)
        {
            printf("Gagal membuat thread, return value = %d\n", cek);
            exit(EXIT_FAILURE);
        }

	//Mulai Game
	while(gameplay)
	{
		//perlihatkan nilai
		printf("Player1: %d || Player2: %d\n", nilai[0], nilai[1]);
		printf("--------------------------\n");
		
		if(play == 0)
		{
			PasangRanjau((void *)&play);
			play= 1;
			TebakRanjau((void *)&play);
		}
		else if(play == 1)
		{
			PasangRanjau((void *)&play);
			play= 0;
			TebakRanjau((void *)&play);
		}
	}

	return 0;
}
