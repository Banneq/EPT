#include "pch.h"
#include "CTable.h"
#include <iostream>

CTable::CTable() {
	s_name = "default";
	std::cout << "without: " << s_name << std::endl;
	arr = new int[5];
	arrLen = 5;
	for (int i = 0; i < arrLen; i++) {
		arr[i] = i;
	}
}

CTable::CTable(std::string sName, int iTableLen) {
	s_name = sName;
	std::cout << "parameter: " << s_name << std::endl;
	arr = new int[iTableLen];
	arrLen = iTableLen;
	for (int i = 0; i < arrLen; i++) {
		arr[i] = i;
	}
}
CTable::CTable(CTable & pcOther) {
	s_name = pcOther.s_name + "_copy";
	this->bSetNewSize(pcOther.arrLen);

	for (int i = 0; i < pcOther.arrLen; i++) {
		arr[i] = pcOther.arr[i];
	}

	std::cout << "copy: " << s_name << std::endl;
	arrLen = pcOther.arrLen;
}

CTable::~CTable() {
	std::cout << "removing: " << s_name << std::endl;
	delete this->arr;
}

void CTable::vSetName(std::string sName) {
	s_name = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
	if (iTableLen <= 0) {
		return false;
	}

	int * newArray = new int[iTableLen];
	for (int i = 0; i < arrLen; i++) {
		newArray[i] = arr[i];
	}
	delete this->arr;
	arr = newArray;

	for (int i = 0; i < arrLen; i++) {
		arr[i] = i + 5;
	}
	return true;
}

CTable * CTable::pcClone() {
	return new CTable(*this);
}

void CTable::showArray() {
	std::cout << "Pritning content of table: " << s_name << std::endl;
	for (int i = 0; i < arrLen; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}