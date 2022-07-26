/*
 ============================================================================
	Fernandez Juan Ignacio 1ºB
	Laboratorio | Parcial Nº2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include "utn.h"

int main(void) {

	setbuf(stdout, NULL);

	LinkedList* listaPokemons = ll_newLinkedList();
	int opcion;
	char nombreArchivo[50];
	int returnAux;
	int flagLoadCsv;
	flagLoadCsv = 0;

	do
	{
		utn_getNumero(&opcion, "\n******* MENU PRINCIPAL *******\n\n"
				"1. Cargar archivo pokemones\n"
				"2. Eliminar pokemon\n"
				"3. Imprimir pokemones\n"
				"4. Filtrar de tipo agua variocolor\n"
				"5. Mapear ataque cargado\n"
				"6. Salir\n\n"
				"Seleccione una opcion: ", "Error, opcion no valida. Intentelo de nuevo: ", 1, 6);

		switch(opcion)
		{
			case 1:
				if(flagLoadCsv == 0)
				{
					utn_getString(nombreArchivo, "Ingresar nombre del archivo: ", "Error, nombre demasiado largo. Intentelo de nuevo: ", 50);
					if(strcmp(nombreArchivo, "Data_Pokemones.csv") == 0)
					{
						returnAux = controller_loadTxt("Data_Pokemones.csv", listaPokemons);
						if(returnAux == 1)
						{
							printf("\nSe cargo con exito los datos del archivo!");
							flagLoadCsv = 1;
						}
						else
						{
							printf("\nError al cargar los datos del archivo");
						}
					}
					else
					{
						printf("\nNo existe un nombre con ese archivo!");
					}
				}
				else
				{
					printf("\nYa se ha cargado el archivo csv previamente!");
				}
				break;
			case 2:
				if(flagLoadCsv == 1)
				{
					controller_listPokemon(listaPokemons);
					returnAux = controller_deletePokemon(listaPokemons);

					if(returnAux == 1)
					{
						printf("\nSe ha eliminado al pokemon de la lista!");
					}
					else
					{
						printf("\nError al eliminar un pokemon de la lista!");
					}
				}
				else
				{
					printf("\nNo se ha cargado ningun archivo! Seleccione la opcion uno para hacerlo.");
				}
				break;
			case 3:
				if(flagLoadCsv == 1)
				{
					controller_listPokemon(listaPokemons);
				}
				else
				{
					printf("\nNo se ha cargado ningun archivo! Seleccione la opcion uno para hacerlo.");
				}
				break;
			case 4:
				if(flagLoadCsv == 1)
				{
					printf("\nPokemones tipo Water shiny:\n");
					returnAux = controller_filtrar(listaPokemons);

					if(returnAux == 1)
					{
						printf("\nSe filtro correctamente la lista!");
					}
					else
					{
						printf("\nError, al filtrar la lista!");
					}
				}
				else
				{
					printf("\nNo se ha cargado ningun archivo! Seleccione la opcion uno para hacerlo.");
				}
				break;
			case 5:
				if(flagLoadCsv == 1)
				{
					returnAux = controller_map(listaPokemons);

					if(returnAux == 1)
					{
						printf("\nValores de ataque mapeados correctamente!");
					}
					else
					{
						printf("\nError al mapear los valores de ataque!");
					}
				}
				else
				{
					printf("\nNo se ha cargado ningun archivo! Seleccione la opcion uno para hacerlo.");
				}
				break;
			default:
				printf("\nPrograma cerrado. Saludos!");
				break;
		}
	}while(opcion != 6);
	return 0;
}
