/*
 * Pokemon.h
 *
 *  Created on: 1 jul. 2022
 *      Author: juan
 */

#ifndef POKEMON_H_
#define POKEMON_H_

#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[20];
	char tipo[20];
	char tamaño[20];
	char ataqueCargado[20];
	int valorAtaque;
	int esVarioColor;

} Pokemon;

Pokemon* Pokemon_new();
Pokemon* Pokemon_newParametros(char* idStr, char* nombreStr, char* tipoStr, char* tamañoStr, char* ataqueCargadoStr, char* valorAtaqueStr, char* esVarioColorStr);
int Pokemon_delete(Pokemon* this);
int Pokemon_setId(Pokemon* this, int id);
int Pokemon_getId(Pokemon* this, int* id);
int Pokemon_setNombre(Pokemon* this, char* nombre);
int Pokemon_getNombre(Pokemon* this, char* nombre);
int Pokemon_setTipo(Pokemon* this, char* tipo);
int Pokemon_getTipo(Pokemon* this, char* tipo);
int Pokemon_setTamaño(Pokemon* this, char* tamaño);
int Pokemon_getTamaño(Pokemon* this, char* tamaño);
int Pokemon_setAtaqueCargado(Pokemon* this, char* ataqueCargado);
int Pokemon_getAtaqueCargado(Pokemon* this, char* ataqueCargado);
int Pokemon_setValorAtaque(Pokemon* this, int valorAtaque);
int Pokemon_getValorAtaque(Pokemon* this, int* valorAtaque);
int Pokemon_setVarioColor(Pokemon* this, int esVarioColor);
int Pokemon_getVarioColor(Pokemon* this, int* esVarioColor);
int Pokemon_setGeneral(Pokemon* this, int id, char* nombre, char* tipo, char* tamaño, char* ataqueCargado, int valorAtaque, int esVarioColor);
int Pokemon_getGeneral(Pokemon* this, int* id, char* nombre, char* tipo, char* tamaño, char* ataqueCargado, int* valorAtaque, int* esVarioColor);
int Pokemon_printOne(Pokemon* this);
int Pokemon_indiceById(LinkedList* listaPokemon, int sizeList,int id);
int Pokemon_filtrarTipo(void* this);
int Pokemon_map(void* this);
int Pokemon_mapDos(void* this);
int Pokemon_count(void* this);

#endif /* POKEMON_H_ */
