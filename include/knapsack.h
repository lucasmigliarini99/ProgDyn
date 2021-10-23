/**
 * @file knapsack.h
 * @author Lucas Migliarini (l.migliarini@eleve.leschartreux.net)
 * @brief 
 * @version 0.1
 * @date 2021-10-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

typedef struct
{
    int cost;
    int weight;
} Object;

Object *knapsack(Object objects[], int size, int W);