#include "main.h"

int main() {
    vDynamicTreeTest();
    vMoveSubTreeDynamic();
    return 0;
}

void vDynamicTreeTest()
{
    cout << endl << "vDynamicTreeTest()" << endl;
    CTreeDynamic<double> c_tree_dyn;
    c_tree_dyn.pcGetRoot()->vAddNewChild();
    c_tree_dyn.pcGetRoot()->vAddNewChild();
    c_tree_dyn.pcGetRoot()->pcGetChild(0)->vSetValue(1.385);
    c_tree_dyn.pcGetRoot()->pcGetChild(1)->vSetValue(2.0);
    c_tree_dyn.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dyn.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dyn.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_tree_dyn.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_tree_dyn.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_dyn.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree_dyn.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_tree_dyn.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);
    c_tree_dyn.vPrintTree();
} //void vDynamicTreeTest()

void vMoveSubTreeDynamic()
{
    cout << endl << "vMoveSubTreeTest() - dynamic nodes" << endl;
    CTreeDynamic<double> c_tree_dyn1, c_tree_dyn2;

    c_tree_dyn1.pcGetRoot()->vSetValue(0);
    c_tree_dyn1.pcGetRoot()->vAddNewChild();
    c_tree_dyn1.pcGetRoot()->vAddNewChild();
    c_tree_dyn1.pcGetRoot()->vAddNewChild();
    c_tree_dyn1.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree_dyn1.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree_dyn1.pcGetRoot()->pcGetChild(2)->vSetValue(3);
    c_tree_dyn1.pcGetRoot()->pcGetChild(2)->vAddNewChild();
    c_tree_dyn1.pcGetRoot()->pcGetChild(2)->pcGetChild(0)->vSetValue(4);

    c_tree_dyn2.pcGetRoot()->vSetValue(50);
    c_tree_dyn2.pcGetRoot()->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->vSetValue(54);
    c_tree_dyn2.pcGetRoot()->pcGetChild(1)->vSetValue(55);
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(56);
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(57);
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild();
    c_tree_dyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vSetValue(58);

    cout << "Before moving subtree" << endl;
    c_tree_dyn1.vPrintTree();
    c_tree_dyn2.vPrintTree();

    CNodeDynamic<double> *pcParent = c_tree_dyn1.pcGetRoot()->pcGetChild(2);
    CNodeDynamic<double> *pcChild = c_tree_dyn2.pcGetRoot()->pcGetChild(0);
    c_tree_dyn1.bMoveSubtree(pcParent , pcChild);
    cout << endl << "After moving subtree" << endl;

    c_tree_dyn1.vPrintTree();
    c_tree_dyn2.vPrintTree();
} //void vMoveSubTreeDynamic()