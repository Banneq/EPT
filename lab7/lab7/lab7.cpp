#include "pch.h"
#include <iostream>
#include "CMySmartPointer.h"

int main()
{
	int * x = new int;
	*x = 5;
	CMySmartPointer<int> smartPtr (x);
	std::cout << *smartPtr << std::endl;
	int * y = new int;
	*y = 10;
	smartPtr = y;
	std::cout << *smartPtr << std::endl;
	int stat = 15;
	smartPtr = &stat;
	std::cout << *smartPtr;
}


