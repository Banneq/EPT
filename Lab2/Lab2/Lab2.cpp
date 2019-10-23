#include "pch.h"
#include <iostream>
#include "CTable.h"

int main()
{
	CTable table("xd", 5);
	CTable * table1 = new CTable("pierwsza", 2);
	table1->showArray();
	CTable * table2 = new CTable(*table1);
	delete table1;
	table2->showArray();
	CTable * table3 = table2->pcClone();
	delete table2;
	table3->showArray();
	delete table3;
	return 0;
}

