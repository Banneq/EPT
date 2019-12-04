#pragma once
#include "CNodeDynamic.h"

template <typename T> class CTreeDynamic
{
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic<T> *pcGetRoot() { return(pc_root); }
	void vPrintTree();
	bool bMoveSubtree(CNodeDynamic <T> *pcParentNode, CNodeDynamic <T> *pcNewChildNode, CNodeDynamic <T> *pc2ParentNode);
private:
	CNodeDynamic <T> *pc_root;
};


template <typename T>
CTreeDynamic<T>::CTreeDynamic()
{
	pc_root = new CNodeDynamic<T>();
}

template <typename T>
CTreeDynamic<T>::~CTreeDynamic()
{
	delete pc_root;
	pc_root = NULL;
}
template <typename T>
void CTreeDynamic<T>::vPrintTree()
{
	if (pc_root != NULL)
		pc_root->vPrintAllBelow();
}
template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> * pcParentNode, CNodeDynamic<T> * pcNewChildNode, CNodeDynamic<T> * pc2ParentNode)
{
	if (pcParentNode == NULL || pcNewChildNode == NULL || pc2ParentNode == NULL)
		return false;

	pc2ParentNode->removeNodeFromChildrenVector(pcNewChildNode);
	pcParentNode->vAddNewChild(pcNewChildNode);
	return true;
}
