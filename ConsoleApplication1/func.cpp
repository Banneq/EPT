#include "func.h"

void print_array(int* array, int iSize) {
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
		arr[i] = i + 5;
	}

	print_array(arr, iSize);

	delete[] arr;
}

bool b_alloc_table_2_dim(int**& piTable, int iSizeX, int iSizeY) {
	if (iSizeX <= 0 || iSizeY <= 0) {
		std::cout << "Array's sizes are supposed to be a positive integer number";
		return false;
	}


	piTable = new (std::nothrow) int* [iSizeY];
	if (piTable == nullptr) {
		return false;
	}

	for (int i = 0; i < iSizeY; i++) {
		piTable[i] = new (std::nothrow) int[iSizeX];
		if (piTable[i] == nullptr) {
			return false;
		}
	}


	return true;
}

bool b_dealloc_table_2_dim(int**& piTable, int iSizeX, int iSizeY) {
	if (iSizeX <= 0 || iSizeY <= 0) {
		std::cout << "Array's sizes are supposed to be a positive integer number";
		return false;
	}

	if (piTable == nullptr) {
		return false;
	}

	for (int i = 0; i < iSizeY; i++) {
		if (piTable[i] == nullptr) {
			return false;
		}
		delete[] piTable[i];
	}
	delete[] piTable;


	return true;
}