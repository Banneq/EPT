#include "pch.h"
#include "CTreeDynamic.h"
#include "CTreeStatic.h"
#include <iostream>

void v_tree_test()
{
	std::cout << "STATIC CASE \n\n";
	CTreeStatic c_root3;
	c_root3.pcGetRoot()->vAddNewChild();
	c_root3.pcGetRoot()->vAddNewChild();
	c_root3.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_root3.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_root3.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root3.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root3.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root3.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root3.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root3.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root3.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root3.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);	c_root3.vPrintTree();	std::cout << std::endl;	CTreeStatic c_root4;
	c_root4.pcGetRoot()->vAddNewChild();
	c_root4.pcGetRoot()->vAddNewChild();
	c_root4.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_root4.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_root4.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root4.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root4.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root4.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root4.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root4.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root4.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root4.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);	c_root4.vPrintTree();	std::cout << std::endl;
	c_root3.bMoveSubtree(c_root3.pcGetRoot()->pcGetChild(1), c_root4.pcGetRoot()->pcGetChild(0), c_root4.pcGetRoot());

	std::cout << "first tree: ";
	c_root3.vPrintTree();

	std::cout << "second tree:";
	c_root4.vPrintTree();
	std::cout << std::endl;
	

	std::cout << "DYNAMIC ALLOCATION CASE \n\n";
	CTreeDynamic c_root;
	c_root.pcGetRoot()->vAddNewChild();
	c_root.pcGetRoot()->vAddNewChild();
	c_root.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_root.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_root.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
	c_root.vPrintTree();
	std::cout << std::endl;

	CTreeDynamic c_root2;
	c_root2.pcGetRoot()->vAddNewChild();
	c_root2.pcGetRoot()->vAddNewChild();
	c_root2.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	c_root2.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	c_root2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	c_root2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	c_root2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	c_root2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root2.pcGetRoot()->pcGetChild(1)->vAddNewChild();
	c_root2.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	c_root2.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
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

