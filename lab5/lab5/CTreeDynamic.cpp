#include "pch.h"
#include "CTreeDynamic.h"


CTreeDynamic::CTreeDynamic()
{
	pc_root = new CNodeDynamic();
}


CTreeDynamic::~CTreeDynamic()
{
	delete pc_root;
	pc_root = NULL;
}

void CTreeDynamic::vPrintTree()
{
	if (pc_root != NULL)
		pc_root->vPrintAllBelow();
}

bool CTreeDynamic::bMoveSubtree(CNodeDynamic * pcParentNode, CNodeDynamic * pcNewChildNode, CNodeDynamic * pc2ParentNode)
{
	if (pcParentNode == NULL || pcNewChildNode == NULL || pc2ParentNode == NULL)
		return false;

	pc2ParentNode->removeNodeFromChildrenVector(pcNewChildNode);
	pcParentNode->vAddNewChild(pcNewChildNode);
	return true;
}
