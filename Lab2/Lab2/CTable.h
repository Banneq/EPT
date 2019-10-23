#pragma once
#include "pch.h"
#include <string>

class CTable {
public:
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(CTable & pcOther);
	~CTable();
	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	void showArray();
	CTable * pcClone();
private:
	std::string s_name;
	int * arr;
	int arrLen;
};