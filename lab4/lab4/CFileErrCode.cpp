#include "pch.h"
#include "CFileErrCode.h"


CFileErrCode::CFileErrCode()
{	
	this->pf_file = new FILE();
}

CFileErrCode::CFileErrCode(std::string sFileName, bool & hasSucceeded)
{
	pf_file = new FILE();
	pf_file = fopen(sFileName.c_str(), "w+");
	hasSucceeded = (pf_file == NULL) ? false : true;
}

CFileErrCode::~CFileErrCode()
{
	if (pf_file != NULL)
		fclose(pf_file);
}

bool CFileErrCode::bOpenFile(std::string sFileName)
{
	pf_file = fopen(sFileName.c_str(), "w+");
	return (pf_file == NULL) ? false : true;
}

bool CFileErrCode::bPrintLine(std::string sText)
{
	if (pf_file == NULL)
	{
		return false;
	}
	fprintf(pf_file, sText.c_str());
	return true;
}

bool CFileErrCode::bPrintManyLines(std::vector<std::string> sText)
{
	bool flag = true;
	for (size_t i = 0; i < sText.size(); i++)
		if (bPrintLine(sText[i]) == false)
			flag = false;
	return flag;
}
