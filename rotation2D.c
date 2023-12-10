#include <stdio.h>
#include <math.h>
#include <windows.h>


#define LINES 20
#define COLUMNS 50

#define PI 3.14

void screen_init(int screen[LINES][COLUMNS]){
	for (int i = 0; i < LINES; i++){
		for (int j = 0; j < COLUMNS; j++){
			screen[i][j] = 0;
		}
	}
}

void screen_display(int screen[LINES][COLUMNS]){
	for (int i = 0; i < LINES; i++){
		for (int j = 0; j < COLUMNS; j++){
			// ajout d'un espace dans le print pour avoir une isométrie, remplacer le caractère si besoin
			if (screen[i][j] == 1) printf(" *");
			// if (screen[i][j] == 1) printf("\033[32m %d\033[0m",screen[i][j]);
			else printf("  ");
			// else printf(" %d",screen[i][j]);
		}
		printf("\n");
	}
}

typedef struct{
	float x;
	float y;	
} Point2D;


Point2D point_rotate(Point2D point, float angle){
	// coordonnées obtenus à partir d'une multiplication avec une matrice de rotation (rotation2D.png)
	float rotateX = point.x*cos(angle) - point.y*sin(angle);

	float rotateY = point.x*sin(angle) + point.y*cos(angle);

	Point2D rotatePoint = {rotateX, rotateY};
	return rotatePoint;

}


int main(void){
	// enlever le curseur
	printf("\x1b[?25l");
	// effacer l'écran (clear/cls)
	printf("\x1b[2J");
	
	int screen[LINES][COLUMNS];
	screen_init(screen);

	// pour répété l'annimation
	int turnNumber = 1;
	
	Point2D pointField[4] = {
		{5,5},
		{5,-5},
		{-5,5},
		{-5,-5}
	};

	for (int i = 0; i < turnNumber; i++){
		// la division est à mofier pour le nombre d'image, ici 50 * 4.
		for (float j = 0; j < 2*PI; j += PI/50){
			// ajouter un index 'l' si vous travaillez sur un plan
			for (int k = 0; k < 4; k++){
				// Les division par 2 sont là pour placer l'origine au centre du screen
				screen[(int)(LINES/2 + point_rotate(pointField[k], j).x)][(int)(COLUMNS/2 + point_rotate(pointField[k], j).y)] = 1;
			}
			// mettre le curseur à la première ligne et première colonne et réécrire par dessous
			printf("\x1b[H");
			screen_display(screen);
			Sleep(1);
			// à commenter si vous voulez voir la trajectoire des points
			screen_init(screen);
		}
		Sleep(1);
	}
	// remettre le curseur
	printf("\x1b[?25h");
	return 0;
}
