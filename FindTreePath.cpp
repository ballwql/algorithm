#include <iostream>
#include <vector>
using namespace std;
typedef struct node
{
	int nData;
	struct node *left;
	struct node *right;
}BSNode,*pTree;
void addBSNode(pTree &pCur,int x) //pCur is reference , value can be dynamic changed
{
	if(NULL==pCur) //if tree node is null, create a new node and assigned to pCur, 
	{
		pTree pNode=new BSNode();
		pNode->left=NULL;
		pNode->right=NULL;
		pNode->nData=x;
		pCur=pNode;
	}else
	{
		if(pCur->nData>x)
			addBSNode(pCur->left,x);
		else if(pCur->nData<x)
			addBSNode(pCur->right,x);
		else  //not allow insert the same element
			return;
	}
}
void FindPath(pTree pNode, int expectedNum,vector<int>& vPath, int &curSum)
{
	if(NULL == pNode)
		return ;
	curSum+=pNode->nData;
	vPath.push_back(pNode->nData);
	if(curSum==expectedNum && (pNode->left==NULL && pNode->right==NULL))
	{
		for(vector<int>::iterator iter=vPath.begin();iter!=vPath.end();++iter)
			cout<<*iter<<" ";
		cout<<endl;

	}
	if(pNode->left)
		FindPath(pNode->left,expectedNum,vPath,curSum);
	if(pNode->right)
		FindPath(pNode->right,expectedNum,vPath,curSum);
	curSum-=pNode->nData;
	vPath.pop_back();
}
void printTree(pTree pHead)
{
	if(NULL==pHead)
		return;

	printTree(pHead->left);
	cout<<pHead->nData<<endl;
	printTree(pHead->right);
}
int main()
{
	int a[]={4,5,10,12,7};
	pTree pRoot=NULL;
	vector<int> path;
	int pathNum=0;
	for(int i=0;i<5;i++)
		addBSNode(pRoot,a[i]);
//	printTree(pRoot);
	FindPath(pRoot,19,path,pathNum);
	return 0;
}