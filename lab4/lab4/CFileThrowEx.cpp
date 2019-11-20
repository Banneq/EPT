#include "pch.h"
#include "CFileThrowEx.h"


CFileThrowEx::CFileThrowEx()
{
	this->pf_file = new FILE();
}

CFileThrowEx::CFileThrowEx(std::string sFileName)
{
	try
	{
		pf_file = new FILE();
		pf_file = fopen(sFileName.c_str(), "w+");
	}
	catch (int err)
	{
		std::cout << "An exception #" << err << std::endl;
	}
}


CFileThrowEx::~CFileThrowEx()
{
	try
	{
		fclose(pf_file);
	}
	catch (int err)
	{
		std::cout << "An exception #" << err << std::endl;
	}
}

void CFileThrowEx::vOpenFile(std::string sFileName)
{
	try
	{
		pf_file = fopen(sFileName.c_str(), "w+");
	}
	catch (int err)
	{
		std::cout << "An exception #" << err << std::endl;
	}
	
	
		
}

void CFileThrowEx::vPrintLine(std::string sText)
{
	try
	{
		fprintf(pf_file, sText.c_str());
	}
	catch (int err)
	{
		std::cout << "An exception #" << err << std::endl;
	}
	
}

void CFileThrowEx::vPrintManyLines(std::vector<std::string> sText)
{
	for (size_t i = 0; i < sText.size(); i++)
		vPrintLine(sText[i]);
}
