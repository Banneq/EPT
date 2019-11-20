#pragma once
#include <string>
#include <vector>

class CFileLastError
{
public:
	CFileLastError();
	CFileLastError(std::string sFileName);
	~CFileLastError();
	void vOpenFile(std::string sFileName);
	void vPrintLine(std::string sText);
	void vPrintManyLines(std::vector<std::string> sText);
	bool bGetLastError() { return(b_last_error); }
private:
	FILE *pf_file;
	bool b_last_error;
};