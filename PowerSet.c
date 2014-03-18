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

#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
#define LISTINCREMENT  10 // 线性表存储空间的分配增量

typedef struct LNode
{
    ElemType data;              // 存储的数据
    struct LNode *next;         // 后继的结点指针
}LNode,*LinkList;
 
void InitList(LinkList *L)
{
    // InitList_L即CreateList_L
    // 顺序(头插法)n个元素的值,建立带表头结点的单链线性表L
//    int i;
    (*L) = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;      // 先建立一个带头结点的单链表
 
} // InitList
 
int ListLength(LinkList L)
{
    // 计算链表长度
    int i=0;
    LinkList p = L->next;
    while(p)
    {
        i++;            // 存在加1
        p = p->next; // 指向下一个结点
    }
    return i;
} // ListLength
 
Status GetElem(LinkList L,int i,ElemType *e)
{
    LNode *p;
    int j;
    // L为带头结点的单链表的头指针
    // 当第i个元素存在时，其值赋给e并返回OK,否则返回false
    p = L->next; j = 1;          // 初始化,p指向第一个结点,j为计数器
 
    while(p && j < i)
    {
        p = p->next; ++j;
    }
 
    if(!p || j>i)
        return ERROR;           // 第i个元素不存在
 
    *e = p->data;             // 取第i个元素
    return OK;
} // GetElem
 
Status ListInsert(LinkList *L,int i,ElemType e)
{
    LinkList p; int j;
    LinkList s = (LinkList)malloc(sizeof(LNode));   // 生成新结点
    // 在带头结点的单链线性表L中第i个位置之前插入元素e
    p = (*L); j = 0;
    while(p && j < i-1)
    {
        p = p->next; ++j;        // 寻找第i-1个结点
    }
 
    if(!p||j>i-1)
        return ERROR;           // i小于1或者大于表长+1
 
    s->data = e; s->next = p->next;                // 插入L中
    p->next = s;
 
    return OK;
 
} // ListInsert
 
Status ListDelete(LinkList *L,int i,ElemType *e)
{
    LinkList p,q; int j;
    // 在带头结点的单链线性表L中,删除第i个元素，并由e返回其值
    p = (*L); j = 0;
    while(p->next && j<i-1)
    {
        // 寻找第i个结点,并令p指向其前趋
        p = p->next; ++j;
    }
 
    if((!p->next) || j > i-1)
        return ERROR;           // 删除位置不合理
 
    q = p->next; p->next = q->next;    // 删除并释放结点
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
 
    // 输出空集
    if (!length)
    {
        printf("Empty");
    }
 
    printf("\n");
 
    return;
}
 
// 算法6.15 P150
// 线性表A表示集合A，线性表B表示幂集ρ(A)的一个元素。
// 局部量k为进入函数时表B的当前长度。
// 第一次调用本函数时，B为空表，i＝1。
void GetPowerSet(int i, LinkList A, LinkList *B) {
   ElemType x;
   int k;
   if (i > ListLength(A))
       Output(*B); // 输出当前B值，即ρ(A)的一个元素
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
 
    printf("请输入集合A的元素个数:\n");
    scanf("%d",&n);
    InitList(&a);
 
    printf("请输入集合中的元素:\n");
    for(i=1;i<=n;i++){
        scanf("%d",&e);
        ListInsert(&a,i,e);
    }
    InitList(&b);
    printf("进行冥集合运算!\n");
    GetPowerSet(1, a, &b);
    return 0;
}
/*
请输入集合A的元素个数：
3
请输入集合A的元素：(空格区分)
1 2 3
*/