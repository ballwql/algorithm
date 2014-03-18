#include <iostream>
using namespace std;
typedef struct node
{
	int value;
	struct node *left;
	struct node *right;
	int maxlen_left;
	int maxlen_right;
}BSTree,*pBSTree;

int nMaxlen=0;

void addBSNode(pBSTree &pCur,int x) //pCur is reference , value can be dynamic changed
{
	if(NULL==pCur) //if tree node is null, create a new node and assigned to pCur, 
	{
		pBSTree pNode=new BSTree();
		pNode->left=NULL;
		pNode->right=NULL;
		pNode->value=x;
		pNode->maxlen_left=0;
		pNode->maxlen_right=0;
		pCur=pNode;
	}else
	{
		if(pCur->value>x)
			addBSNode(pCur->left,x);
		else if(pCur->value<x)
			addBSNode(pCur->right,x);
		else  //not allow insert the same element
			return;
	}
}
void FindMaxlen(pBSTree pRoot)
{
	if(pRoot==NULL)
		return;
	if(pRoot->left==NULL)
		pRoot->maxlen_left=0;
	if(pRoot->right==NULL)
		pRoot->maxlen_right=0;
	if(pRoot->left!=NULL)
		FindMaxlen(pRoot->left);
	if(pRoot->right!=NULL)
		FindMaxlen(pRoot->right);
	if(pRoot->left!=NULL)
	{
		int nTmplen=0;
		if(pRoot->left->maxlen_left>pRoot->left->maxlen_right)
			nTmplen=pRoot->left->maxlen_left;
		else
			nTmplen=pRoot->right->maxlen_right;
		pRoot->maxlen_left=nTmplen+1;
	}
	if(pRoot->right!=NULL)
	{
		int nTmpMax=0;
		if(pRoot->right->maxlen_left>pRoot->right->maxlen_right)
			nTmpMax=pRoot->right->maxlen_left;
		else
			nTmpMax=pRoot->right->maxlen_right;
		pRoot->maxlen_right=nTmpMax+1;
	}
	if(pRoot->maxlen_left+pRoot->maxlen_right>nMaxlen)
		nMaxlen=pRoot->maxlen_left+pRoot->maxlen_right;
}

int main()
{
	pBSTree pRoot=NULL;
	
	int a[]={8,6,10,5,7,9,11};
	int i=0;
	for(i=0;i<7;i++)
		addBSNode(pRoot,a[i]);
	FindMaxlen(pRoot);
	cout<<nMaxlen<<endl;
	return 0;
}
