/**
 * @file knapsack.c
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
#include "../../include/knapsack.h"


/**
 * @brief Tris tableau selon les c/w decroissant
 * @param objects The array of values
 * @param size The size of the array
 * @param ascending ascending: 0 or 1 for descending, asceneding
 */

void insertionsort(Object tab[], int size)
{
   int j;
   for (int i = 1; i < size; i++)
   {
      Object object = tab[i];
      j = i - 1;
      while (j >= 0 && (object.cost/object.weight < tab[j].cost/tab[j].weight))
      {
            tab[j + 1] = tab[j];
            j = j - 1;
      }
      tab[j + 1] = object;
   }
}

/**
 * @brief Ajoute dans le sac l'objet le plus lourd
 * @param objects The array of values
 * @param size The size of the array
 * @param W weight max backpack
 */

Object *knapsack(Object objects[], int size, int W){ 
    Object *backpack = (Object *)malloc(sizeof(Object));;
    insertionsort(objects, size);
    int current_weight = 0;
    for(int i =0; i < size; i++){
        if(current_weight + objects[i].weight <= W){
            current_weight += objects[i].weight;
            backpack[i] = objects[i];
        }
    }
    return backpack;
}