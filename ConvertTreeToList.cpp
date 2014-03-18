#include <iostream>
using namespace std;
typedef struct BSTreeNode
{
	int m_nVal;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
}DoubleList,*pList;
pList pHead;
pList pListIndex;

void convertToList(pList pCur);
void addBSNode(pList &pCur,int x) //pCur is reference , value can be dynamic changed
{
	if(NULL==pCur) //if tree node is null, create a new node and assigned to pCur, 
	{
		pList pNode=new DoubleList();
		pNode->left=NULL;
		pNode->right=NULL;
		pNode->m_nVal=x;
		pCur=pNode;
	}else
	{
		if(pCur->m_nVal>x)
			addBSNode(pCur->left,x);
		else if(pCur->m_nVal<x)
			addBSNode(pCur->right,x);
		else  //not allow insert the same element
			return;
	}
}
void InOrder(pList pCur) 
{
	if(pCur != NULL)
	{
		if(pCur->left != NULL)
			InOrder(pCur->left);
		convertToList(pCur);
		if(pCur->right !=NULL)
			InOrder(pCur->right);

			
	}
}
void convertToList(pList pCur)
{
	pCur->left=pListIndex;
	if(pListIndex==NULL)
		pHead=pCur;
	else
		pListIndex->right=pCur;
	pListIndex=pCur;
	cout<<pCur->m_nVal<<endl;
}
int main()
{
	pList pRoot=NULL;
	pListIndex=NULL;
	pHead=NULL;
	int a[]={10,4,6,8,12,14,15,16};
	for(int i=0;i<8;i++)
		addBSNode(pRoot,a[i]);
	InOrder(pRoot);
	return 0;
}
