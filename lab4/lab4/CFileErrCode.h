#pragma once
#include <string>
#include <vector>

class CFileErrCode
{
public:
	CFileErrCode();
	CFileErrCode(std::string sFileName, bool & hasSucceeded);
	~CFileErrCode();
	bool bOpenFile(std::string sFileName);
	bool bPrintLine(std::string sText);
	bool bPrintManyLines(std::vector<std::string> sText);
private:
	FILE *pf_file;
};