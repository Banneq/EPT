#include "pch.h"
#include "CFileErrCode.h"
#include "CFileLastError.h"
#include "CFileThrowEx.h"
#include <iostream>



int main()
{
	std::string fileName = "file.txt";

	CFileErrCode * errCode = new CFileErrCode();
	for (int i = 0; i < 10; i++)
		std::cout << errCode->bOpenFile(fileName) << std::endl;
	delete errCode;
	std::cout << std::endl << std::endl;
	

	CFileLastError * lastError = new CFileLastError();
	for (int i = 0; i < 10; i++)
	{
		lastError->vOpenFile(fileName);
		std::cout << lastError->bGetLastError() << std::endl;
	}
	delete lastError;
	std::cout << std::endl << std::endl;

	CFileThrowEx * throwEx = new CFileThrowEx();
	for (int i = 0; i < 10; i++)
		throwEx->vOpenFile(fileName);
	delete throwEx;
	std::cout << std::endl << std::endl;
}

