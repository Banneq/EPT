#include "pch.h"
#include <iostream>
#include "CTab.h"

int main()
{
	CTab tab1;
	CTab tab2;
	tab2 = std::move(tab1) + std::move(tab2);
	std::cout << std::endl;

	CTab tab3;
	CTab tab4;
	tab3 = tab3 + tab4;
	std::cout << std::endl;


	CTab tab5;
	CTab tab6;
	tab5 = tab6;
	std::cout << std::endl;

	CTab tab7;
	CTab tab8;
	tab8 = std::move(tab7);
}

