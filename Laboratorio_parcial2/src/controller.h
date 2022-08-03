/*
 * controller.h
 *
 *  Created on: 1 jul. 2022
 *      Author: juan
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "LinkedList.h"

int controller_loadTxt(char* path, LinkedList* listaPokemon);
int controller_listPokemon(LinkedList* listaPokemon);
int controller_deletePokemon(LinkedList* listaPokemon);
int controller_filtrar(LinkedList* this);
int controller_map(LinkedList* this, int opcion);
int controller_count(LinkedList* this);

#endif /* CONTROLLER_H_ */
