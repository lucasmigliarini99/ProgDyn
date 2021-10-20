/**
 * @file functions.c
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
#include "../include/functions.h"

/**
 * @brief Recherche par dichotomie dans un tableau d'entiers
 * @param array The array of values
 * @param size_t The size of the array
 * @param value The value to find
 * @return The position of the value found or -1
 */
int find_by_dichotomy(int array[], int size_t, int value )
{
    /* initialisation des valeurs*/
    int pos = -1,taille = size_t-1;

    /* Recherche de la position de la valeur */
    
    for (int i=0 ; (i<taille)&&(pos==-1) ; i++)
        if (array[i]==value)
            pos=i;
    /* Edition du résultat */
    if (pos==-1)
        return -1;
    else
        return pos; 
}