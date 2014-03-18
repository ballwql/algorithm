#include <iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node* next;
}List,*pList;
pList createList()
{
	pList head,p,q;
	head=new List;
	head=NULL;
	int num;
	cin>>num;
	while(num!=-1)
	{
		
		p=new List;
		p->data=num;
		p->next=NULL;
		if(head==NULL)
		{
			head=p;
			q=head;
		}
		else
		{
			q->next=p;
			q=p;
		}		
		cin>>num;
	}
	return head;
}
void Print(pList head)
{
	pList p=head;
	while(p)
	{
		if(p->next==NULL)
			cout<<p->data;
		else
			cout<<p->data<<" -> ";
		p=p->next;
	}
	cout<<endl;
}
pList Merge(pList head1, pList head2)
{
	if(head1==NULL && head2==NULL)
		return NULL;
	if(head1==NULL&&head2)
		return head2;
	if(head1 && head2==NULL)
		return head1;
	pList p,q,pre,tmp;
	pre=NULL;
	p=head1;
	q=head2;
	while(p && q)
	{
		if(p->data<q->data)
		{
			pre=p;
			p=p->next;
		}
		else
		{
			tmp=q;
			q=q->next;
			tmp->next=p;
			pre->next=tmp;
			pre=tmp;
		}
	}
	if(q)
		pre->next=q;
	return head1;	
}
int main()
{
	pList head1,head2;
	head1=new List;
	head2=new List;
	head1=createList();
	head2=createList();
	Merge(head1,head2);
	Print(head1);

	return 0;
}
