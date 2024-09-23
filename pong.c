#include <stdio.h>
#include <math.h>
#define TAILLE 10
#include <windows.h>

typedef struct{
	int x;
	int y;
	int vector[2];	
}Ball;



void afficher(int screen[TAILLE][TAILLE],int lenght, Ball *ball1);
void gameloop();
void moveball(Ball *ball);
void collition(Ball *ball, int dirrection);
int main(){
	int screen[TAILLE][TAILLE] = {0};
	int lenght = sqrt(sizeof(screen) / sizeof(int));
	Ball ball1 = { 0, 5, {1, 1}};
	
	gameloop(lenght, ball1, screen);
}


void collition(Ball *ball, int dirrection){
	if (dirrection == 1) {
		ball->vector[1] = -ball->vector[1];
	
	}
	else{
		ball->vector[0] = -ball->vector[0];
	}
}

void moveball(Ball *ball){
	if ((ball->y + ball->vector[1]) < TAILLE || ((ball->y + ball->vector[1])) < 0) {
		ball->y += ball->vector[1];
	}
	else{
		collition(ball, 1);
	}
	if  ((ball->x + ball->vector[0]) < TAILLE || ((ball->x + ball->vector[0])) <0) {
		ball->x += ball->vector[0];
	}	
	else{
		collition(ball, 0);
	}

	printf("%d %d", ball->x, ball->vector[0]);
}

void afficher(int screen[TAILLE][TAILLE], int lenght, Ball *ball1){
system("cls");
	printf("matrice de taille %d", lenght);	
	for (int y = 0; y < lenght; y++){
		printf("\n");
		for (int x = 0; x < lenght; x++){
			if (ball1->x == x && ball1->y == y){
				printf("O ");
			}
			else{
			printf("%d ", screen[y][x]);
			}
		}
	}
}




void gameloop(int lenght,Ball *ball1,int screen[TAILLE][TAILLE]){
	moveball(ball1);
	afficher(screen, lenght, ball1);
	Sleep(1000);
	gameloop(lenght, ball1, screen);

}



