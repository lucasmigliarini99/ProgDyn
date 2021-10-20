/**
 * @file main.c
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

int main()
{
	int tab[10] = {1,2,3,4,5,6,7,8,9,10};
	int result = find_by_dichotomy (tab, 10, 5);
	if (result == -1)
		printf("La valeur recherchée ne se trouve pas "
            "dans le tableau.\n");
	else
		printf("La valeur se trouve à la position %d. \n",result);
	
}