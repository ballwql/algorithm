#include <iostream>
using namespace std;
typedef struct BSTreeNode
{
	int m_nVal;
	struct BSTreeNode *left;
	struct BSTreeNode *right;
}DoubleList,*pList;

int tArr[100]; //store the sequence of postorder 
int k=0;

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

void PostOrder(pList pCur)
{
	if(pCur != NULL)
	{
		PostOrder(pCur->left);
		PostOrder(pCur->right);
		tArr[k++]=pCur->m_nVal;
	}
}

vint main()
{
	pList pRoot=NULL;
	pListIndex=NULL;
	pHead=NULL;
	int a[]={8,6,10,5,7,9,11};
	int seq_order[]={5,7,6,9,11,10,8};
	int i=0,j=0;
	for(i=0;i<7;i++)
		addBSNode(pRoot,a[i]);

	PostOrder(pRoot);
	i=j=0;
	while(i<7&&j<k)
	{
		if(seq_order[i]!=tArr[j])
		{
			break;
		}
		i++;
		j++;
	}
	if(i<7 || j<7)
		cout<<"给定序列不是后缀序列"<<endl;
	return 0;
}
