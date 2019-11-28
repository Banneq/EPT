#pragma once
#include <vector>
#include <iostream>

class CNodeDynamic
{
public:
	CNodeDynamic() { i_val = 0; parent = NULL; };
	~CNodeDynamic();
	void vSetValue(int iNewVal) { i_val = iNewVal; };
	int iGetChildrenNumber() { return v_children.size(); };
	void vAddNewChild();
	void vAddNewChild(CNodeDynamic * node);
	CNodeDynamic *pcGetChild(int iChildOffset);
	void vPrint() { std::cout << " " << i_val; };
	void vPrintAllBelow();
	CNodeDynamic * getParent() { return parent; }
	bool removeNodeFromChildrenVector(CNodeDynamic * node);
private:
	std::vector<CNodeDynamic *> v_children;
	int i_val;
	CNodeDynamic * parent;
	void printAllBelow(CNodeDynamic * node);
};