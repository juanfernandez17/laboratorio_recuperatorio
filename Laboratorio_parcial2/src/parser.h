/*
 * parser.h
 *
 *  Created on: 1 jul. 2022
 *      Author: juan
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "LinkedList.h"
#include "Pokemon.h"
#include <stdio.h>

int parser_pokemonTxt(FILE* pFile, LinkedList* listaPokemon);

#endif /* PARSER_H_ */
