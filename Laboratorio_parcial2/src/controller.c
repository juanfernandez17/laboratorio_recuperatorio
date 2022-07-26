/*
 * controller.c
 *
 *  Created on: 1 jul. 2022
 *      Author: juan
 */

#include "controller.h"
#include "utn.h"
#include "Pokemon.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

int controller_loadTxt(char* path, LinkedList* listaPokemon)
{
	int returnAux;
	FILE* pArchivo;
	returnAux = -1;

	if(path != NULL && listaPokemon != NULL)
	{
		pArchivo = fopen(path, "r");

		if(pArchivo != NULL)
		{
			parser_pokemonTxt(pArchivo, listaPokemon);
			fclose(pArchivo);
			returnAux = 1;
		}
	}
	return returnAux;
}

int controller_listPokemon(LinkedList* listaPokemon)
{
	int returnAux;
	Pokemon* unPokemon;
	int sizeList;
	returnAux = -1;

	if(listaPokemon != NULL)
	{
		sizeList = ll_len(listaPokemon);
		printf("\n====================================================================================================\n");
		printf("ID\tNOMBRE\t\tTIPO\t  TAMAÑO\tATAQUE CARGADO\t    VALOR DE ATAQUE\tVARIO COLOR\n");
		printf("====================================================================================================");
		for(int i = 0; i < sizeList; i++)
		{
			unPokemon = (Pokemon*) ll_get(listaPokemon, i);

			if(unPokemon != NULL)
			{
				Pokemon_printOne(unPokemon);
			}
		}
		returnAux = 1;
	}
	return returnAux;
}

int controller_deletePokemon(LinkedList* listaPokemon)
{
	int returnAux;
	int idPokemon;
	int sizeList;
	int indice;
	Pokemon* eliminarPokemon;
	returnAux = -1;

	if(listaPokemon != NULL)
	{
		sizeList = ll_len(listaPokemon);
		utn_getNumero(&idPokemon, "\n\nIngresar ID del pokemon a eliminar: ", "Error, intentelo de nuevo: ", 1, sizeList);
		indice = Pokemon_indiceById(listaPokemon, sizeList, idPokemon);

		eliminarPokemon = (Pokemon*) ll_pop(listaPokemon, indice);

		if(eliminarPokemon != NULL)
		{
			Pokemon_printOne(eliminarPokemon);
			returnAux = 1;
		}
	}
	return returnAux;
}

int controller_filtrar(LinkedList* this)
{
	int returnAux;
	LinkedList* nuevaLista;
	returnAux = -1;

	if(this != NULL)
	{
		nuevaLista = ll_filter(this, Pokemon_filtrarTipo);
		controller_listPokemon(nuevaLista);
		returnAux = 1;
	}
	return returnAux;
}

int controller_map(LinkedList* this)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL)
	{
		returnAux = ll_map(this, Pokemon_map);
	}
	return returnAux;
}
