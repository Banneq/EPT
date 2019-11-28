#pragma once

#include <iostream>
#include <vector>

class CNodeStatic
{
public:
	CNodeStatic() { i_val = 0; parent = NULL;};
	~CNodeStatic();
	void vSetValue(int iNewVal) { i_val = iNewVal; };
	int iGetChildrenNumber() { return(v_children.size()); };
	void vAddNewChild();
	void vAddNewChild(CNodeStatic * node);
	CNodeStatic * pcGetChild(int iChildOffset);
	void vPrint() { std::cout << " " << i_val; };
	void vPrintAllBelow();
	void vPrintUp();
	bool removeNodeFromChildrenVector(CNodeStatic * node);
private:
	std::vector<CNodeStatic> v_children;
	void printAllBelow(CNodeStatic node);
	int i_val;
	CNodeStatic* parent;
};

