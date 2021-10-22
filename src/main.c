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
#include <assert.h>
#include "../include/functions.h"

int main()
{
	///////////////////exo1///////////////////
	int tab[10] = {1,2,3,4,5,6,7,8,9,10};
	int result = find_by_dichotomy (tab, 10, 11);
	if (result == -1)
		printf("La valeur recherchée ne se trouve pas "
            "dans le tableau.\n");
	else
		printf("La valeur se trouve à la position %d. \n",result);

	
	///////////////////exo2///////////////////

	Object object1,object2,object3;
	object1.cost = 7;
	object1.weight = 6;

	object2.cost = 5;
	object2.weight = 5;
	
	object3.cost = 5;
	object3.weight = 5;

	Object objects[3] = {object1, object2,object3};

	Object *backpack;
	backpack = knapsack(objects, 3, 10);
	Object *endPtr = backpack + sizeof(backpack)/sizeof(backpack[0]);
	while(backpack < endPtr){
		printf("L'object w : %d, c: %d\n", backpack->weight,backpack->cost);
		assert(backpack->weight == 6);
		assert(backpack->cost == 7);
		backpack++;
	}
	
	
	
	
	
}