#define N 10
#include "stdio.h"
int w[N+1];  //the weight of each object
int p[N+1];  //the property of each object
int c; //bag capacity
int bestp=0;//the most property value
int cp=0;//current value of bag
int cw=0;//current weight of bag
int n; //actual number of objects

void Sort()// sort the object by value of weight/value in descend
{
	int i,j,k,tmp1;
	float tmp2;
	float pw[N+1];
	for(j=1;j<=n;++j)
		pw[j]=p[i]/w[i];
	for(i=1;i<=n-1;++i)
	{
		k=i;
		for(j=i+1;j<=n;++j)
			if(pw[j]>pw[k])
				k=j;
		if(k!=i)
		{
			tmp2=pw[i];
			pw[i]=pw[k];
			pw[k]=tmp2;
			tmp1=w[i];
			w[i]=w[k];
			w[k]=tmp1;
			tmp1=p[i];
			p[i]=p[k];
			p[k]=tmp1;
		}

	}
}

int Bound(int i)
{
	int j=i;
	int cleft = c-cw; //remain capacity of bag
	float b=cp;
	while((j<=n)&&(w[j]<cleft))
	{
		cleft-=w[i];
		b+=p[j];
		++j;
	}
	if((j<=n)&&w[j]>cleft)
		b+=cleft*(p[i]/w[i]);
	return b;
}
void Backtrack(int i)
{
	if(i>n)
	{
		bestp=cp;
		return;
	}
	if(cw+w[i]<=c) //left tree
	{
		cw+=w[i];
		cp+=p[i];
		Backtrack(i+1);
		cw-=w[i];
		cp-=p[i];
		if(Bound(i+1)>bestp)
			Backtrack(i+1);
	}
}
int main()
{
	 int i;
    bestp=0; 
    printf("请输入背包最大容量:\n");
    scanf("%d",&c);
    printf("请输入物品个数:\n");
    scanf("%d",&n);
    printf("请依次输入物品的重量:\n");
    for(i=1;i<=n;i++) 
        scanf("%d",&w[i]);
    printf("请依次输入物品的价值:\n");
    for(i=1;i<=n;i++) 
        scanf("%d",&p[i]);
	Sort();
    Backtrack(1);
    printf("最大价值为:\n");
    printf("%d\n",bestp);
    printf("被选中的物品依次是(0表示未选中，1表示选中)\n");
    
	return 0;
}