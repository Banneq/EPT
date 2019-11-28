#include "pch.h"
#include "CNodeDynamic.h"
#include <algorithm>


CNodeDynamic::~CNodeDynamic()
{
	while (this->iGetChildrenNumber() > 0)
	{
		CNodeDynamic * currNode = this;
		while (currNode->iGetChildrenNumber() > 0)
			currNode = currNode->pcGetChild(0);

		CNodeDynamic * parent = currNode->parent;
		parent->v_children.erase(parent->v_children.begin(), parent->v_children.begin() + 1);
		delete currNode;
	}
	
}

void CNodeDynamic::vAddNewChild()
{
	CNodeDynamic * newChild = new CNodeDynamic();
	newChild->parent = this;
	v_children.push_back(newChild);
}

void CNodeDynamic::vAddNewChild(CNodeDynamic * node)
{
	if (node == NULL)
		return;
	node->parent = this;
	v_children.push_back(node);
}

CNodeDynamic * CNodeDynamic::pcGetChild(int iChildOffset)
{
	if (iChildOffset < 0 || iChildOffset >= iGetChildrenNumber())
		return NULL;
	return v_children[iChildOffset];
}

void CNodeDynamic::vPrintAllBelow()
{
	printAllBelow(this);
}


bool CNodeDynamic::removeNodeFromChildrenVector(CNodeDynamic * node)
{
	if (node == NULL)
		return false;

	for (int i = 0; i < iGetChildrenNumber(); i++)
		if (pcGetChild(i) == node)
		{
			v_children.erase(v_children.begin() + i, v_children.begin() + i + 1);
			return true;
		}
	return false;
}

void CNodeDynamic::printAllBelow(CNodeDynamic * node)
{
	if (node == NULL)
		return;
	node->vPrint();
	
	if (node->iGetChildrenNumber() == 0)
		return;

	for (size_t i = 0; i < node->v_children.size(); i++)
		printAllBelow(node->v_children[i]);
}
