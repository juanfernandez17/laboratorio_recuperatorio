/*
 * Pokemon.c
 *
 *  Created on: 1 jul. 2022
 *      Author: juan
 */

#include "Pokemon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Pokemon* Pokemon_new()
{
	Pokemon* nuevoPokemon;

	nuevoPokemon = (Pokemon*) malloc(sizeof(Pokemon));

	if(nuevoPokemon != NULL)
	{
		nuevoPokemon->id = 0;
		strcpy(nuevoPokemon->nombre, "\0");
		strcpy(nuevoPokemon->tipo, "\0");
		strcpy(nuevoPokemon->tamaño, "\0");
		strcpy(nuevoPokemon->ataqueCargado, "\0");
		nuevoPokemon->valorAtaque = 0;
		nuevoPokemon->esVarioColor = 0;
	}
	return nuevoPokemon;
}

Pokemon* Pokemon_newParametros(char* idStr, char* nombreStr, char* tipoStr, char* tamañoStr, char* ataqueCargadoStr, char* valorAtaqueStr, char* esVarioColorStr)
{
	Pokemon* nuevoPokemon;
	int id;
	char nombre[20];
	char tipo[20];
	char tamaño[20];
	char ataqueCargado[20];
	int valorAtaque;
	int esVarioColor;

	nuevoPokemon = Pokemon_new();

	if(nuevoPokemon != NULL)
	{
		id = atoi(idStr);
		strcpy(nombre, nombreStr);
		strcpy(tipo, tipoStr);
		strcpy(tamaño, tamañoStr);
		strcpy(ataqueCargado, ataqueCargadoStr);
		valorAtaque = atoi(valorAtaqueStr);
		esVarioColor = atoi(esVarioColorStr);

		if(Pokemon_setGeneral(nuevoPokemon, id, nombre, tipo, tamaño, ataqueCargado, valorAtaque, esVarioColor) != 1)
		{
			Pokemon_delete(nuevoPokemon);
			nuevoPokemon =  NULL;
		}
	}
	return nuevoPokemon;
}

int Pokemon_delete(Pokemon* this)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL)
	{
		free(this);
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_setId(Pokemon* this, int id)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_getId(Pokemon* this, int* id)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_setNombre(Pokemon* this, char* nombre)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_getNombre(Pokemon* this, char* nombre)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy( nombre, this->nombre);
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_setTipo(Pokemon* this, char* tipo)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && tipo != NULL)
	{
		strcpy(this->tipo, tipo);
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_getTipo(Pokemon* this, char* tipo)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && tipo != NULL)
	{
		strcpy( tipo, this->tipo);
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_setTamaño(Pokemon* this, char* tamaño)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && tamaño != NULL)
	{
		strcpy(this->tamaño, tamaño);
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_getTamaño(Pokemon* this, char* tamaño)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && tamaño != NULL)
	{
		strcpy(tamaño, this->tamaño);
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_setAtaqueCargado(Pokemon* this, char* ataqueCargado)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && ataqueCargado != NULL)
	{
		strcpy(this->ataqueCargado, ataqueCargado);
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_getAtaqueCargado(Pokemon* this, char* ataqueCargado)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && ataqueCargado != NULL)
	{
		strcpy(ataqueCargado, this->ataqueCargado);
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_setValorAtaque(Pokemon* this, int valorAtaque)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && valorAtaque > 0)
	{
		this->valorAtaque = valorAtaque;
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_getValorAtaque(Pokemon* this, int* valorAtaque)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && valorAtaque != NULL)
	{
		*valorAtaque = this->valorAtaque;
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_setVarioColor(Pokemon* this, int esVarioColor)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && esVarioColor > -1)
	{
		this->esVarioColor = esVarioColor;
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_getVarioColor(Pokemon* this, int* esVarioColor)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && esVarioColor != NULL)
	{
		*esVarioColor = this->esVarioColor;
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_setGeneral(Pokemon* this, int id, char* nombre, char* tipo, char* tamaño, char* ataqueCargado, int valorAtaque, int esVarioColor)
{
	int returnAux;
	returnAux = -1;

	if(	this != NULL && id > 0 && nombre != NULL && tipo != NULL && tamaño != NULL &&  ataqueCargado != NULL && valorAtaque > 0 && esVarioColor > -1 &&
		Pokemon_setId(this, id) && Pokemon_setNombre(this, nombre) && Pokemon_setTipo(this, tipo) && Pokemon_setTamaño(this, tamaño) && Pokemon_setAtaqueCargado(this, ataqueCargado) &&
		Pokemon_setValorAtaque(this, valorAtaque) && Pokemon_setVarioColor(this, esVarioColor))
	{
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_getGeneral(Pokemon* this, int* id, char* nombre, char* tipo, char* tamaño, char* ataqueCargado, int* valorAtaque, int* esVarioColor)
{
	int returnAux;
	returnAux = -1;

	if(	this != NULL && id != NULL && nombre != NULL && tipo != NULL && tamaño != NULL && ataqueCargado != NULL && valorAtaque != NULL && esVarioColor!= NULL &&
		Pokemon_getId(this, id) && Pokemon_getNombre(this, nombre) && Pokemon_getTipo(this, tipo) && Pokemon_getTamaño(this, tamaño) && Pokemon_getAtaqueCargado(this, ataqueCargado) &&
		Pokemon_getValorAtaque(this, valorAtaque) && Pokemon_getVarioColor(this, esVarioColor))
	{
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_printOne(Pokemon* this)
{
	int returnAux;
	int id;
	char nombre[20];
	char tipo[20];
	char tamaño[20];
	char ataqueCargado[20];
	int valorAtaque;
	int esVarioColor;
	returnAux = -1;

	if(this != NULL)
	{
		Pokemon_getGeneral(this, &id, nombre, tipo, tamaño, ataqueCargado, &valorAtaque, &esVarioColor);
		printf("\n%-4d | %-10s | %-10s | %-10s | %-20s | %-15d | %-11d |\n", id, nombre, tipo, tamaño, ataqueCargado, valorAtaque, esVarioColor);
		printf("----------------------------------------------------------------------------------------------------");
	}
	return returnAux;
}

int Pokemon_indiceById(LinkedList* listaPokemon, int sizeList,int id)
{
	int indice;
	Pokemon* unPokemon;
	int idPokemon;

	indice = -1;

	if(listaPokemon != NULL && sizeList > 0&& id > 0)
	{
		for(int i = 0; i < sizeList; i++)
		{
			unPokemon = (Pokemon*) ll_get(listaPokemon, i);
			Pokemon_getId(unPokemon, &idPokemon);

			if(idPokemon == id)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int Pokemon_filtrarTipo(void* this)
{
	int returnAux;
	char tipoPokemon[20];
	int esVarioColor;
	Pokemon* unPokemon;
	returnAux = -1;

	if(this != NULL)
	{
		unPokemon = (Pokemon*) this;
		Pokemon_getTipo(this, tipoPokemon);
		Pokemon_getVarioColor(unPokemon, &esVarioColor);

		if(strcmp("Water", tipoPokemon) == 0 && esVarioColor == 1)
		{
			returnAux = 1;
		}
	}
	return returnAux;
}

int Pokemon_map(void* this)
{
	int returnAux;
	char tipo[20];
	int valorAtaque;
	Pokemon* unPokemon;
	returnAux = -1;

	if(this != NULL)
	{
		unPokemon = (Pokemon*) this;
		Pokemon_getTipo(unPokemon, tipo);

		if(strcmp(tipo, "Fire") == 0 || strcmp(tipo, "Ground") == 0 || strcmp(tipo, "Grass") == 0)
		{
			Pokemon_getValorAtaque(unPokemon, &valorAtaque);
			valorAtaque = valorAtaque * 1.1;
			Pokemon_setValorAtaque(unPokemon, valorAtaque);
			returnAux = 1;
		}
	}
	return returnAux;
}

int Pokemon_mapDos(void* this)
{
	int returnAux;
	char tipo[20];
	char tamaño[20];
	int valorAtaque;
	Pokemon* unPokemon;

	returnAux = -1;

	if(this != NULL)
	{
		unPokemon = (Pokemon*) this;
		Pokemon_getTipo(unPokemon, tipo);
		Pokemon_getTamaño(unPokemon, tamaño);
		Pokemon_getValorAtaque(unPokemon, &valorAtaque);

		if(strcmp(tipo, "Bug") == 0 || strcmp(tipo, "Fire") == 0 || strcmp(tipo, "Grass") == 0)
		{
			if(strcmp(tamaño, "XL") == 0)
			{
				valorAtaque = valorAtaque * 1.2;
			}
			else
			{
				if(strcmp(tamaño, "L") == 0)
				{
					valorAtaque = valorAtaque * 1.1;
				}
				else
				{
					valorAtaque = valorAtaque * 1.05;
				}
			}
		}
		Pokemon_setValorAtaque(unPokemon, valorAtaque);
		returnAux = 1;
	}
	return returnAux;
}

int Pokemon_count(void* this)
{
	int returnAux;
	char tipo[20];
	char tamaño[20];
	char ataqueCargado[20];
	int valorAtaque;
	Pokemon* unPokemon;

	returnAux = -1;

	if(this != NULL)
	{
		unPokemon = (Pokemon*) this;

		if(unPokemon != NULL)
		{
			Pokemon_getTipo(unPokemon, tipo);
			Pokemon_getTamaño(unPokemon, tamaño);
			Pokemon_getAtaqueCargado(unPokemon, ataqueCargado);
			Pokemon_getValorAtaque(unPokemon, &valorAtaque);

			if(((strcmp(tipo, "Fire") == 0) && (strcmp(tamaño, "XL") == 0) && (strcmp(ataqueCargado, "LanzaLlamas") == 0) && valorAtaque > 80) ||
				((strcmp(tipo, "Water") == 0) && (strcmp(tamaño, "L") == 0) && (strcmp(ataqueCargado, "Hidrobomba") == 0) && valorAtaque > 80))
				{
					returnAux = 1;
				}
		}
	}
	return returnAux;
}
