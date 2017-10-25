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
int tmp, lubang;

void *CekSelesai(void *argv)
{
	int i, ranjau, id= *((int *)argv);
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

void *PasangRanjau(void *playerid)
{
	int i;
	if (*((int *)playerid) == 0)
		printf("Player1 memasang ranjau!\n");
	else
		printf("Player2 memasang ranjau!\n");
	do
	{
		printf("Berapa ranjau yang akan dipasang? ");
		scanf("%d", &tmp);
		if(tmp < 1 || tmp > 4)	printf("Maaf, hanya bisa memasang 1-4 ranjau saja.\n");
	}while (tmp < 1 || tmp > 4);

	printf("Pasang ranjau pada lubang (0-15) ke? ");
	for (i = 0; i < tmp; i++)
	{
		scanf("%d", &lubang);
		board[*((int *)playerid)][lubang]= 1;
	}
	return NULL;
}

void *TebakRanjau(void *playerid)
{
	int i;
	if (*((int *)playerid) == 0)
		printf("Silahkan Player1 untuk menebak!\n");
	else
		printf("Silahkan Player2 untuk menebak!\n");
	printf("Pilih lubang yang menurut anda aman dari ranjau! ");
	for(i=0;i<4;i++){	
		scanf("%d", &tmp);
		if (board[(*((int *)playerid)+1)%2][tmp] == 0)
		{
			nilai[*((int *)playerid)]++;
		}
		else
		{
			nilai[(*((int *)playerid)+1)%2]++;
		}
	}
	return NULL;
}


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
