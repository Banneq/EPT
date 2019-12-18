#include "pch.h"
#include "CTab.h"

#include <iostream>
#include <algorithm>

CTab::CTab(const CTab &cOther)
{
	v_copy(cOther);
	std::cout << "Copy ";
}
CTab::CTab(CTab && cOther)
{
	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;
	cOther.pi_tab = NULL;
	cOther.i_size = 0;
	std::cout << "MOVE ";
}
//CTab::CTab(const CTab &cOther)
CTab::~CTab()
{
	if (pi_tab != NULL) delete pi_tab;
	std::cout << "Destr ";
}
bool CTab::bSetSize(int iNewSize)
{
	if (i_size <= 0) {
		return false;
	}

	int * newArray = new int[i_size];
	for (int i = 0; i < std::min(i_size, iNewSize); i++) {
		newArray[i] = pi_tab[i];
	}
	delete this->pi_tab;
	pi_tab = newArray;
	i_size = iNewSize;
	return true;
}
//CTab::~CTab()
CTab CTab::operator=(const CTab &cOther)
{
	if (pi_tab != NULL) delete pi_tab;
	v_copy(cOther);
	std::cout << "op= ";
	return(*this);
}
CTab& CTab::operator=(CTab && cOther)
{
	if (pi_tab != NULL) delete pi_tab;
	pi_tab = cOther.pi_tab;
	i_size = cOther.i_size;
	cOther.i_size = 0;
	cOther.pi_tab = NULL;
	return *this;
}

CTab CTab::operator+(const CTab cOther)
{
	CTab newTab;
	newTab.bSetSize(i_size + cOther.i_size);
	for (int i = 0; i < i_size; i++)
		newTab.pi_tab[i] = pi_tab[i];
	for (int i = i_size; i < i_size; i++)
		newTab.pi_tab[i] = cOther.pi_tab[i - i_size];
	return newTab;
}

void CTab::v_copy(const CTab &cOther)
{
	pi_tab = new int[cOther.i_size];
	i_size = cOther.i_size;
	for (int ii = 0; ii < cOther.i_size; ii++)
		pi_tab[ii] = cOther.pi_tab[ii];
}