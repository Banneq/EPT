#include "pch.h"
#include "CNodeStatic.h"


CNodeStatic::~CNodeStatic()
{
	v_children.clear();
}

void CNodeStatic::vAddNewChild()
{
	CNodeStatic newNode;
	newNode.parent = this;
	v_children.push_back(newNode);
}

void CNodeStatic::vAddNewChild(CNodeStatic * node)
{
	if (node == NULL)
		return;
	node->parent = this;
	v_children.push_back(*node);
}

CNodeStatic * CNodeStatic::pcGetChild(int iChildOffset)
{
	if (iChildOffset < 0 || iChildOffset >= iGetChildrenNumber())
		return NULL;
	return &v_children[iChildOffset];
}

void CNodeStatic::vPrintAllBelow()
{
	printAllBelow(*this);
}

void CNodeStatic::vPrintUp()
{
	CNodeStatic *curr = this;
	while (curr != NULL)
	{
		curr->vPrint();
		curr = curr->parent;
	} 
}

bool CNodeStatic::removeNodeFromChildrenVector(CNodeStatic * node)
{
	for (size_t i = 0; i < iGetChildrenNumber(); i++)
		if (pcGetChild(i) == node)
		{
			v_children.erase(v_children.begin() + i, v_children.begin() + i + 1);
			return true;
		}
	return false;
}

void CNodeStatic::printAllBelow(CNodeStatic node)
{
	node.vPrint();
	if (node.iGetChildrenNumber() == 0)
		return;
	

	for (size_t i = 0; i < node.v_children.size(); i++)
		printAllBelow(*node.pcGetChild(i));
}





