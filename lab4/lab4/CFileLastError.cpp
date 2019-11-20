#include "pch.h"
#include "CFileLastError.h"

CFileLastError::CFileLastError()
{
	b_last_error = false;
	this->pf_file = new FILE();
}

CFileLastError::CFileLastError(std::string sFileName)
{
	b_last_error = false;
	pf_file = new FILE();
	pf_file = fopen(sFileName.c_str(), "w+");
	if (pf_file == NULL)
		b_last_error = true;
}

CFileLastError::~CFileLastError()
{
	if (pf_file != NULL)
		fclose(pf_file);
}

void CFileLastError::vOpenFile(std::string sFileName)
{
	b_last_error = false;
	pf_file = fopen(sFileName.c_str(), "w+");
	if (pf_file == NULL)
		b_last_error = true;
}

void CFileLastError::vPrintLine(std::string sText)
{
	b_last_error = false;
	if (pf_file == NULL)
	{
		b_last_error = true;
		return;
	}
	fprintf(pf_file, sText.c_str());
}

void CFileLastError::vPrintManyLines(std::vector<std::string> sText)
{
	for (int i = 0; i < sText.size(); i++)
		vPrintLine(sText[i]);
}
