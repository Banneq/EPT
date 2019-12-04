#include "pch.h"
#include "CTreeDynamic.h"
#include <iostream>

void v_tree_test()
{
	std::cout << "DYNAMIC ALLOCATION CASE \n\n";
	CTreeDynamic <double> c_root;
	c_root.pcGetRoot()->vAddNewChild();
	c_root.pcGetRoot()->vAddNewChild();
	c_root.pcGetRoot()->pcGetChild(0)->vSetValue(1.1);
	c_root.pcGetRoot()->pcGetChild(1)->vSetValue(2.1);
	c_root.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11.5);
	c_root.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12.5);
	c_root.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21.5);
	c_root.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22.5);
	c_root.vPrintTree();
	std::cout << std::endl;

	CTreeDynamic <double> c_root2;
	c_root2.pcGetRoot()->vAddNewChild();
	c_root2.pcGetRoot()->vAddNewChild();
	c_root2.pcGetRoot()->pcGetChild(0)->vSetValue(1.1);
	c_root2.pcGetRoot()->pcGetChild(1)->vSetValue(2.2);
	c_root2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11.6);
	c_root2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12.7);
	c_root2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21.8);
	c_root2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22.9);
	c_root2.vPrintTree();
	std::cout << std::endl;

	c_root.bMoveSubtree(c_root.pcGetRoot()->pcGetChild(1), c_root2.pcGetRoot()->pcGetChild(0), c_root2.pcGetRoot());

	std::cout << "first tree: ";
	c_root.vPrintTree();

	std::cout << "second tree:";
	c_root2.vPrintTree();

}//void v_tree_test()




int main()
{
	v_tree_test();


}

