/**
 * @file freeSquare.h
 * @author Lucas Migliarini (l.migliarini@eleve.leschartreux.net)
 * @brief 
 * @version 0.1
 * @date 2021-10-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

typedef struct{
    int x;
    int y;
    int size;
} Coord;

int **initMatrix(int size,int obstacle );
void affichageMatrice (int **matrice, int size);
Coord pgcb(int **matrice, int size);
void newAffichageMatrice(int **matrice, int size, Coord c);