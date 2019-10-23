#include "pch.h"
#include "func.h"
#include <iostream>


void showArray(int* array, int iSize) {
	if (iSize <= 0) {
		std::cout << "Array's size is supposed to be a positive integer number";
		return;
	}
	if (array == NULL) {
		return;
	}
	for (int i = 0; i < iSize; i++) {
		std::cout << *(array + i) << " ";
	}
	std::cout << std::endl;
}

void v_alloc_table_add_5(int iSize) {
	if (iSize <= 0) {
		std::cout << "Array's size is supposed to be a positive integer number";
		return;
	}

	int* arr = new int[iSize];
	for (int i = 0; i < iSize; i++) {
		*(arr+i) = i + 5;
	}

	showArray(arr, iSize);

	delete[] arr;
}

bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) {
	if (iSizeX <= 0 || iSizeY <= 0) {
		std::cout << "Array's sizes are supposed to be a positive integer number";
		*piTable = NULL;
		return false;
	}


	*piTable = new int*[iSizeY];
	if (*piTable == nullptr) {
		return false;
	}

	for (int i = 0; i < iSizeY; i++) {
		*(*piTable + i) = new  int[iSizeX];
	}
	return true;
}

bool b_dealloc_table_2_dim(int*** piTable, int iSizeY) {
	if (iSizeY <= 0) {
		std::cout << "Array's size is supposed to be a positive integer number";
		return false;
	}
	if (*piTable == NULL) {
		std::cout << "Cannot deallocate null pointer" << std::endl;
	}


	for (int i = 0; i < iSizeY; i++) {
		delete[] * (*piTable + i);
		*(*piTable + i) = NULL;
	}
	delete[] * piTable;
	*piTable = NULL;
	return true;
}

int * v_alloc_return_add_5(int iSize) {
	if (iSize <= 0) {
		std::cout << "Array's size is supposed to be a positive integer number" << std::endl;
		return NULL;
	}

	int * array = new int[iSize];
	for (int i = 0; i < iSize; i++) {
		*(array+i) = i + 5;
	}
	return array;
}

bool v_alloc_change_pointer_add_5(int ** ptr, int iSize) {
	if (iSize <= 0) {
		std::cout << "Array's size is supposed to be a positive integer number";
		return false;
	}
	if (*ptr == NULL) {
		std::cout << "Cannot deallocate null pointer" << std::endl;
	}

	*ptr = new int[iSize];
	for (int i = 0; i < iSize; i++) {
		*(*ptr+i) = i + 5;
	}
	return true;
}

void dealloc(int ** ptr) {
	if (*ptr == NULL) {
		return;
	}
	delete[] * ptr;
	*ptr = NULL;
}