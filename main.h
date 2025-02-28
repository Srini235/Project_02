#ifndef MAIN_H
#define MAIN_H

// General introduction:
// This header file contains the declarations for the functions and variables
// used in the main.c file. It serves as an interface between the main program
// and the other modules, ensuring proper linkage and compilation.

// Includes
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Function declarations
void binary_search_manual(void);
uint8_t storeArrayData(uint8_t *array);
void printArrayData(uint8_t search_index_u8, uint8_t *array);
void binarySearch(void);
uint8_t binarySearchNew(uint8_t num_elements_u8,uint8_t *array, uint8_t search_value_u8);

// Variable declarations
extern int someVariable;

#endif // MAIN_H