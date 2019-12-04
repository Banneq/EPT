#pragma once
#include <vector>
#include <iostream>

template <typename T> class CNodeDynamic
{
public:
	CNodeDynamic() { i_val = 0; parent = NULL; };
	~CNodeDynamic();
	void vSetValue(T iNewVal) { i_val = iNewVal; };
	int iGetChildrenNumber() { return v_children.size(); };
	void vAddNewChild();
	void vAddNewChild(CNodeDynamic<T> * node);
	CNodeDynamic<T> *pcGetChild(int iChildOffset);
	void vPrint() { std::cout << " " << i_val; };
	void vPrintAllBelow();
	CNodeDynamic<T> * getParent() { return parent; }
	bool removeNodeFromChildrenVector(CNodeDynamic<T> * node);
private:
	std::vector<CNodeDynamic<T> *> v_children;
	T i_val;
	CNodeDynamic<T> * parent;
	void printAllBelow(CNodeDynamic<T> * node);
};

template <typename T>
CNodeDynamic<T>::~CNodeDynamic()
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
template <typename T>
void CNodeDynamic<T>::vAddNewChild()
{
	CNodeDynamic * newChild = new CNodeDynamic();
	newChild->parent = this;
	v_children.push_back(newChild);
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T> * node)
{
	if (node == NULL)
		return;
	node->parent = this;
	v_children.push_back(node);
}

template <typename T>
CNodeDynamic<T> * CNodeDynamic<T>::pcGetChild(int iChildOffset)
{
	if (iChildOffset < 0 || iChildOffset >= iGetChildrenNumber())
		return NULL;
	return v_children[iChildOffset];
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow()
{
	printAllBelow(this);
}

template <typename T>
bool CNodeDynamic<T>::removeNodeFromChildrenVector(CNodeDynamic<T> * node)
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

template <typename T>
void CNodeDynamic<T>::printAllBelow(CNodeDynamic<T> * node)
{
	if (node == NULL)
		return;
	node->vPrint();

	if (node->iGetChildrenNumber() == 0)
		return;

	for (size_t i = 0; i < node->v_children.size(); i++)
		printAllBelow(node->v_children[i]);
}
