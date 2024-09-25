#include <stdio.h>
#include <math.h>
#define TAILLE 10
#include <SDL2/SDL.h>
#include <unistd.h>
typedef struct{
        int up;
        int down;
        int left;
        int right;
}Inputs;

typedef struct{
        int x;
        int y;
        int vector[2];
        int radius;
}Ball;

typedef struct{
        int x;
        int y;
        int longeur;
        int largeur;
        int velocite[2];
}Rect;


void afficher(int screen[TAILLE][TAILLE],int lenght, Ball *ball1, Rect *rect1, Rect *rect2);
void update(int screen[TAILLE][TAILLE], int lenght, Ball *ball1, Rect *rect1, Rect *rect2);
void gameloop();
void moveball(Ball *ball);
void collition(Ball *ball, int dirrection);
void rect(Rect *, Rect *);
void doInput();
void doKeyDown(SDL_KeyboardEvent *);
void doKeyUp(SDL_KeyboardEvent *);


Inputs inp = {0, 0, 0, 0};


int main(){

        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
                printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
        }

        // Create a window
        SDL_Window* window = SDL_CreateWindow("SDL Keyboard Event Example",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          800, 600, SDL_WINDOW_SHOWN);
        if (!window) {
                printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
        }
        int screen[TAILLE][TAILLE] = {0};
        int lenght = sqrt(sizeof(screen) / sizeof(int));
        Ball ball1 = { 0, 5, {1, 1}};
        Rect rect1 = {0, 3, 2, 1, {0, 0}};
        Rect rect2 = {TAILLE,3, 2, 1, {0, 0}};

        gameloop(lenght, ball1, screen, rect1, rect2, inp);
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


void moverect(Rect *rect1, Rect *rect2){



}



void afficher(int screen[TAILLE][TAILLE], int lenght, Ball *ball1, Rect *rect1, Rect *rect2){
system("clear");
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

void update(int screen[TAILLE][TAILLE], int lenght, Ball *ball1, Rect *rect1, Rect *rect2) {
        moverect(rect1, rect2);
        moveball(ball1);
        doInput();

}


void gameloop(int (*screen)[10],int lenght,Ball *ball, Rect *rect1, Rect *rect2, Inputs inp){
        afficher(screen, lenght, ball, rect1, rect2);
        update(screen, lenght, ball, rect1, rect2);
        if (inp.up){
                printf("amazing");
        }
        sleep(1);
        gameloop(screen, lenght, ball, rect1, rect2, inp);

}

void doInput(){
        SDL_Event event;
        while(SDL_PollEvent(&event)){
                switch(event.type){
                        case SDL_QUIT:exit(0);break;
                        case SDL_KEYDOWN:doKeyDown(&event.key);break;
                        case SDL_KEYUP:doKeyUp(&event.key);break;
                        default:break;
                }}}
void doKeyDown(SDL_KeyboardEvent *event){
        if(event->repeat==0){
                if(event->keysym.scancode==SDL_SCANCODE_UP){inp.up=1;}
                if(event->keysym.scancode==SDL_SCANCODE_DOWN){inp.down=1;}
                if(event->keysym.scancode==SDL_SCANCODE_LEFT){inp.left=1;}
                if(event->keysym.scancode==SDL_SCANCODE_RIGHT){inp.right=1;}
        }}

void doKeyUp(SDL_KeyboardEvent *event){
        if(event->repeat==0){
                if(event->keysym.scancode==SDL_SCANCODE_UP){inp.up=0;}
                if(event->keysym.scancode==SDL_SCANCODE_DOWN){inp.down=0;}
                if(event->keysym.scancode==SDL_SCANCODE_LEFT){inp.left=0;}
                if(event->keysym.scancode==SDL_SCANCODE_RIGHT){inp.right=0;}
        }}
