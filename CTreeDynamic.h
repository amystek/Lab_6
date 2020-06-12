#ifndef LAB_6_CTREEDYNAMIC_H
#define LAB_6_CTREEDYNAMIC_H

#include <vector>
#include "iostream"

using namespace std;

template <typename T>
class  CNodeDynamic
{
public:
    CNodeDynamic() { pc_parent = NULL;};
    ~CNodeDynamic();
    void vSetValue(T tNewVal) {t_val = tNewVal;};
    int iGetChildrenNumber() {return v_children.size();};
    void vAddNewChild();
    void vAddNewChild(CNodeDynamic*);
    void vPrint() {cout << " " << t_val;};
    void vPrintAllBelow();
    void vPrintUp();
    CNodeDynamic<T> *pcGetChild(int iChildOffset);
    CNodeDynamic<T> *pcGetParent() {return pc_parent;};
    void vEraseChild(CNodeDynamic*);
    void vSetParent(CNodeDynamic<T>* ptNewParent) {pc_parent = ptNewParent;};
    vector<CNodeDynamic *> v_children;
private:
    T t_val;
    CNodeDynamic *pc_parent;
};

//class CNodeDynamic

template <typename T>
class CTreeDynamic
{
private:
    CNodeDynamic<T> *pc_root;

public:
    CTreeDynamic() {pc_root = new CNodeDynamic<T>();}
    ~CTreeDynamic() {delete pc_root;}
    CNodeDynamic<T> *pcGetRoot() {return (pc_root);}
    void  vPrintTree();
    bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);
}; //class CTreeDynamic

template<typename T>
void CNodeDynamic<T>::vAddNewChild()
{
    CNodeDynamic<T> *cNewNode = new CNodeDynamic();
    cNewNode->pc_parent = this;
    v_children.push_back(cNewNode);
} //void CNodeDynamic<T>::vAddNewChild()

template<typename T>
void CNodeDynamic<T>::vAddNewChild(CNodeDynamic<T> *pcNewChild)
{
    CNodeDynamic<T> *c_NewNode = new CNodeDynamic();
    c_NewNode->vSetValue(pcNewChild->t_val);
    for (int ii = 0; ii < pcNewChild->iGetChildrenNumber(); ii++)
    {
        c_NewNode->v_children.push_back(pcNewChild->pcGetChild(ii));
    } //for (vector<CNodeStatic>::iterator ii = pcNewChild->v_children.begin(); ii != pcNewChild->v_children.end(); ii++)

    c_NewNode->pc_parent = this;
    v_children.push_back(c_NewNode);
} //void CNodeDynamic<T>::vAddNewChild(CNodeDynamic *)

template<typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset)
{
    if (iChildOffset < 0 or iChildOffset > iGetChildrenNumber())
    {
        return NULL;
    } //if (iChildOffset < 0 or iChildOffset > iGetChildrenNumber())

    return v_children.at(iChildOffset);
} //CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset)

template<typename T>
void CTreeDynamic<T>::vPrintTree()
{
    pc_root->vPrintAllBelow();
    cout << endl;
} //void CTreeDynamic<T>::vPrintTree()

template<typename T>
void CNodeDynamic<T>::vPrintAllBelow()
{
    vPrint();
//    if (iGetChildrenNumber() == 0) {  return; }
    for (int ii = 0; ii < iGetChildrenNumber(); ii++)
    {
        pcGetChild(ii)->vPrintAllBelow();
    } //for (int ii = 00; ii < iGetChildrenNumber(); ii++)
} //void CNodeDynamic<T>::vPrintAllBelow()

template<typename T>
void CNodeDynamic<T>::vPrintUp()
{
    vPrint();
    if (pcGetParent() != NULL)
    {
        pcGetParent()->vPrintUp();
    } //if (pcGetParent() != NULL)
} //void CNodeDynamic<T>::void vPrintUp()

template<typename T>
CNodeDynamic<T>::~CNodeDynamic()
{
    for (int ii = 0; ii < iGetChildrenNumber(); ii++)
    {
        delete v_children.at(ii);
    } //for (int ii = 0; ii < iGetChildrenNumber(); ii++)
} //CNodeDynamic<T>::~CNodeDynamic()

//TODO
template<typename T>
void CNodeDynamic<T>::vEraseChild(CNodeDynamic *pcChildToErase)
{
    if (pcChildToErase->pcGetParent() == NULL)
    {
        pcChildToErase = NULL;
        return;
    } //if (pcChildToErase->pcGetParent() == NULL)

    CNodeDynamic* pc_ParentNode = pcChildToErase->pcGetParent();
    for (int ii = 0; ii < iGetChildrenNumber(); ii++)
    {
        if (pc_ParentNode->pcGetChild(ii) == pcChildToErase)
        {
            pc_ParentNode->v_children.erase(pc_ParentNode->v_children.begin() + ii);
            break;  // break FOR loop after finding first match
        } //if (&(*ii) == pcChildToErase)
    } //for (int ii = 00; ii < iGetChildrenNumber(); ii++)
} //void CNodeDynamic<T>::vEraseChild(CNodeDynamic *pcChildToErase)

template<typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode)
{
    if (pcParentNode == NULL || pcNewChildNode == NULL) return false;
    if (pcParentNode == pcNewChildNode) return false;

    pcParentNode->vAddNewChild(pcNewChildNode);
    pcNewChildNode->vEraseChild(pcNewChildNode);
    return true;
} //bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode)

#endif //LAB_6_CTREEDYNAMIC_H
