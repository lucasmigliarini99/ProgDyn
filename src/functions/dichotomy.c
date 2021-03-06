/**
 * @file dichotomy.c
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
#include "../../include/dichotomy.h"

/**
 * @brief Recherche par dichotomie dans un tableau d'entiers
 * @param array tableau
 * @param size_t taille du tableau
 * @param value valeur à trouver
 * @return la position ou -1 si non trouvée
 */
int find_by_dichotomy(int array[], int size_t, int value )
{
    /* initialisation des valeurs*/
    int index = 0,min = 0, max = size_t-1;

    /* Recherche de la position de la valeur */
    
    while ( min <= max ) {
        index = (min + max) / 2;
        if (array[ index ] == value)
            return index;
        if ( array[ index ] < value )
            min = index+1;
        else
            max = index-1;
    }
    return -1;
}