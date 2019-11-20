#pragma once
#include <string>
#include <vector>
#include <iostream>

class CFileThrowEx
{
public:
	CFileThrowEx();
	CFileThrowEx(std::string sFileName);
	~CFileThrowEx();
	void vOpenFile(std::string sFileName);
	void vPrintLine(std::string sText);
	void vPrintManyLines(std::vector<std::string> sText);
private:
	FILE *pf_file;
};