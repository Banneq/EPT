#pragma once
#include "CNodeStatic.h"
class CTreeStatic
{
public:
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic * pcGetRoot() { return(&c_root); }
	void vPrintTree();
	bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode, CNodeStatic *pc2ParentNode);

private:
	CNodeStatic c_root;
};

