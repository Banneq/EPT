#pragma once

#include <iostream>

void showArray(int* array, int iSize);
void v_alloc_table_add_5(int iSize);
bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY);
bool b_dealloc_table_2_dim(int*** piTable, int iSizeY);
int * v_alloc_return_add_5(int iSize);
bool v_alloc_change_pointer_add_5(int ** ptr, int iSize);
void dealloc(int ** ptr);