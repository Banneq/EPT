#ifndef FUNC_H
#define FUNC_H

#include <iostream>

void print_array(int* array, int iSize);
void v_alloc_table_add_5(int iSize);
bool b_alloc_table_2_dim(int**& piTable, int iSizeX, int iSizeY);
bool b_dealloc_table_2_dim(int**& piTable, int iSizeX, int iSizeY);


#endif