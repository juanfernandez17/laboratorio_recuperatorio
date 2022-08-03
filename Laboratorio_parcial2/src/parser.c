/*
 * parser.c
 *
 *  Created on: 1 jul. 2022
 *      Author: juan
 */

#include "parser.h"

int parser_pokemonTxt(FILE* pFile, LinkedList* listaPokemon)
{
	int returnAux;
	char idStr[20];
	char nombreStr[20];
	char tipoStr[20];
	char tamañoStr[20];
	char ataqueCargadoStr[20];
	char valorAtaqueStr[20];
	char esVarioColorStr[20];
	int datosLeidos;
	Pokemon* nuevoPokemon;

	returnAux = -1;

	if(pFile != NULL && listaPokemon != NULL)
	{
		do
		{
			datosLeidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, tipoStr, tamañoStr, ataqueCargadoStr, valorAtaqueStr, esVarioColorStr);
			nuevoPokemon = Pokemon_newParametros(idStr, nombreStr, tipoStr, tamañoStr, ataqueCargadoStr, valorAtaqueStr, esVarioColorStr);

			if(nuevoPokemon != NULL)
			{
				ll_add(listaPokemon, nuevoPokemon);
			}
		} while(!feof(pFile) && datosLeidos == 7);
		returnAux = 1;
	}
	return returnAux;
}
