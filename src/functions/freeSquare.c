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

#include <stdio.h>
#include <stdlib.h>
#include "../../include/freeSquare.h"


/**
 * @brief initialisation de  la matrice
 * @param size taille du tableau
 * @param obstacle  Nombre d'obstacle dans la matrice
 */

int **initMatrice(int size, int obstacle )
{
    int **matrice = (int **)calloc(size, sizeof(int *));
    for (int i = 0; i < size; i++)
        matrice[i] = (int *)calloc(size, sizeof(int));


    for (int i = 0; i < obstacle ; i++)
    {
        int l_index = rand() % size;
        int c_index = rand() % size;
        matrice[l_index][c_index] = 1;
    }
    return matrice;
}

/**
 * @brief Affichage de la matrice
 * @param matrice matrice
 * @param size  taille de la matrice
 */

void affichageMatrice (int **matrice, int size)
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (matrice[i][j] == 0)
                printf("%c ", ' ');
            if (matrice[i][j] == 1)
                printf("%c ", '*');
        }
        printf("\n");
    }
}

/**
 * @brief  retourne la valeur la plus petite
 * @note   
 * @param  a premiere valeur
 * @param  b seconde valeur
 * @retval 
 */
int min(int a, int b)
{
    return a < b ? a : b;
}

/**
 * @brief  Trouve le plus grand carré dans la matrice
 * @param matrice matrice
 * @param size  taille de la matrice
 */
Coord findMax(int **matrice, int size)
{
    int max = 0;
    Coord coords;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrice[i][j] >= max)
            {
                max = matrice[i][j];
                coords.x = i;
                coords.y = j;
                coords.size = max/2;
            }
        }
    }
    return coords;
}

/**
 * @brief   Explorer la matrice pour trouver le plus grand carré
 * @param matrice matrice
 * @param size  taille de la matrice
 */

Coord pgcb(int **matrice, int size)
{
    int **S = (int **)calloc(size, sizeof(int *));
    for (int i = 0; i < size; i++)
        S[i] = (int *)calloc(size, sizeof(int));

    S[0] = matrice[0];
    for (int l = 1; l < size; l++)
    {
        S[l][0] = matrice[l][0];
    }

    for (int i = 1; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (matrice[i][j] == 0)
                S[i][j] = min(S[i][j - 1], min(S[i - 1][j], S[i - 1][j - 1])) + 2;
            else if (matrice[i][j] == 1)
                S[i][j] = 1;
        }
    }
    Coord coords = findMax(S, size);
    return coords;
    
}

/**
 * @brief  Affiche la matrice finale
 * @param matrice matrice
 * @param size  taille de la matrice
 * @param  c : Coordonnées du carré maximal
 */

void newAffichageMatrice(int **matrice, int size, Coord c){    
    for(int i = (c.x - c.size) + 1; i <= c.x; i++){
        for(int j = (c.y - c.size) + 1; j <= c.y; j++){
            matrice[i][j] = 2;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (matrice[i][j] == 0){
                printf("%c ", ' ');
                continue;
            }
            if (matrice[i][j] == 1){
                printf("%c ", '*');
                continue;
            }
            if(matrice[i][j] == 2)
                printf("%c ", '#');
        }
        printf("\n");
    }
}