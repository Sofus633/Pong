#include <stdio.h>
#include <math.h>
#define TAILLE 50


void afficher(int screen[TAILLE][TAILLE],int lenght);
void gameloop();

int main(){
	int screen[TAILLE][TAILLE] = {0};
	int lenght = sqrt(sizeof(screen) / sizeof(int));

	afficher(screen, lenght);
}

void afficher(int screen[TAILLE][TAILLE], int lenght){
	printf("matrice de taille %d", lenght);	
	for (int y = 0; y < lenght; y++){
		printf("\n");
		for (int x = 0; x < lenght; x++){
			printf("%d ", screen[y][x]);
		}
	}
}

void gameloop(){
}

typedef struct
        {
	
}Balle;
