#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0
#define OK    1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW   -2

#define ElemType int
#define Status   int

#define LIST_INIT_SIZE 100 // ���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT  10 // ���Ա�洢�ռ�ķ�������

typedef struct LNode
{
    ElemType data;              // �洢������
    struct LNode *next;         // ��̵Ľ��ָ��
}LNode,*LinkList;
 
void InitList(LinkList *L)
{
    // InitList_L��CreateList_L
    // ˳��(ͷ�巨)n��Ԫ�ص�ֵ,��������ͷ���ĵ������Ա�L
//    int i;
    (*L) = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;      // �Ƚ���һ����ͷ���ĵ�����
 
} // InitList
 
int ListLength(LinkList L)
{
    // ����������
    int i=0;
    LinkList p = L->next;
    while(p)
    {
        i++;            // ���ڼ�1
        p = p->next; // ָ����һ�����
    }
    return i;
} // ListLength
 
Status GetElem(LinkList L,int i,ElemType *e)
{
    LNode *p;
    int j;
    // LΪ��ͷ���ĵ������ͷָ��
    // ����i��Ԫ�ش���ʱ����ֵ����e������OK,���򷵻�false
    p = L->next; j = 1;          // ��ʼ��,pָ���һ�����,jΪ������
 
    while(p && j < i)
    {
        p = p->next; ++j;
    }
 
    if(!p || j>i)
        return ERROR;           // ��i��Ԫ�ز�����
 
    *e = p->data;             // ȡ��i��Ԫ��
    return OK;
} // GetElem
 
Status ListInsert(LinkList *L,int i,ElemType e)
{
    LinkList p; int j;
    LinkList s = (LinkList)malloc(sizeof(LNode));   // �����½��
    // �ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
    p = (*L); j = 0;
    while(p && j < i-1)
    {
        p = p->next; ++j;        // Ѱ�ҵ�i-1�����
    }
 
    if(!p||j>i-1)
        return ERROR;           // iС��1���ߴ��ڱ�+1
 
    s->data = e; s->next = p->next;                // ����L��
    p->next = s;
 
    return OK;
 
} // ListInsert
 
Status ListDelete(LinkList *L,int i,ElemType *e)
{
    LinkList p,q; int j;
    // �ڴ�ͷ���ĵ������Ա�L��,ɾ����i��Ԫ�أ�����e������ֵ
    p = (*L); j = 0;
    while(p->next && j<i-1)
    {
        // Ѱ�ҵ�i�����,����pָ����ǰ��
        p = p->next; ++j;
    }
 
    if((!p->next) || j > i-1)
        return ERROR;           // ɾ��λ�ò�����
 
    q = p->next; p->next = q->next;    // ɾ�����ͷŽ��
    *e = q->data; free(q);
 
    return OK;
 
} // ListDelete
 
void Output(LinkList L){
    int e,i = 1;
 
    int length = ListLength(L);
 
    for( i;i<=length;++i)
    {
        GetElem(L,i,&e);
        printf("%d ",e);
    }
 
    // ����ռ�
    if (!length)
    {
        printf("Empty");
    }
 
    printf("\n");
 
    return;
}
 
// �㷨6.15 P150
// ���Ա�A��ʾ����A�����Ա�B��ʾ�ݼ���(A)��һ��Ԫ�ء�
// �ֲ���kΪ���뺯��ʱ��B�ĵ�ǰ���ȡ�
// ��һ�ε��ñ�����ʱ��BΪ�ձ�i��1��
void GetPowerSet(int i, LinkList A, LinkList *B) {
   ElemType x;
   int k;
   if (i > ListLength(A))
       Output(*B); // �����ǰBֵ������(A)��һ��Ԫ��
   else {
      GetElem(A, i, &x);
      k = ListLength(*B);
      ListInsert(B, k+1, x);
      GetPowerSet(i+1, A, B);
      ListDelete(B, k+1, &x);
      GetPowerSet(i+1, A, B);
   }
}
 
int main(){
    int n,i;
    ElemType e;
    LinkList a,b;
 
    printf("�����뼯��A��Ԫ�ظ���:\n");
    scanf("%d",&n);
    InitList(&a);
 
    printf("�����뼯���е�Ԫ��:\n");
    for(i=1;i<=n;i++){
        scanf("%d",&e);
        ListInsert(&a,i,e);
    }
    InitList(&b);
    printf("����ڤ��������!\n");
    GetPowerSet(1, a, &b);
    return 0;
}
/*
�����뼯��A��Ԫ�ظ�����
3
�����뼯��A��Ԫ�أ�(�ո�����)
1 2 3
*/