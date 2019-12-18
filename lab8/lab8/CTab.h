#pragma once
#define DEF_TAB_SIZE 10
class CTab
{
public:
	CTab() { pi_tab = new int[DEF_TAB_SIZE]; i_size = DEF_TAB_SIZE; }
	CTab(const CTab &cOther);
	CTab(CTab &&cOther);
	CTab operator=(const CTab &cOther);
	~CTab();
	bool bSetSize(int iNewSize);
	int iGetSize() { return(i_size); }
	CTab& operator=( CTab && cOther);
	CTab operator+(const CTab cOther);
	int * pi_tab;
private:
	void v_copy(const CTab &cOther);
	
	int i_size;
};