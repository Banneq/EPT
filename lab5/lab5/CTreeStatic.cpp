#include "pch.h"
#include "CTreeStatic.h"


CTreeStatic::CTreeStatic()
{

}


CTreeStatic::~CTreeStatic()
{
	c_root.~CNodeStatic();
}

void CTreeStatic::vPrintTree()
{
	pcGetRoot()->vPrintAllBelow();
}

bool CTreeStatic::bMoveSubtree(CNodeStatic * pcParentNode, CNodeStatic * pcNewChildNode, CNodeStatic * pc2ParentNode)
{
	if (pcParentNode == NULL || pcNewChildNode == NULL || pc2ParentNode == NULL)
		return false;

	CNodeStatic clone = *pcNewChildNode;
	pc2ParentNode->removeNodeFromChildrenVector(pcNewChildNode);
	pcParentNode->vAddNewChild(&clone);
	return true;
}
