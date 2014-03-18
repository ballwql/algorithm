#include <iostream>
#include <cmath>
using namespace std;

int getMax(int a[],int size)
{
	int max=0;
	for(int i=0;i<size;++i)
		if(a[i]>max)
			max=a[i];
	return max;
}
int getMaxBit(int maxnum)
{
	int num=0;
	while(maxnum)
	{
		maxnum/=10;
		num++;
	}
	return num;
}
void CountSort(int a[],int size)
{
	int maxNum=getMax(a,size);
	int loop=getMaxBit(maxNum);
	int i=0,j=0,k=0,inx=0;
	int *arr[10];
	for(i=0;i<10;++i)
	{
		arr[i]=new int[size];
		memset(arr[i],0,size*sizeof(int));
	}
	
	for(i=0;i<loop;++i)
	{
		
		for(j=0;j<size;++j)
		{
			int rowInx=((int)a[j]/(int)pow(10,i))%10;
			for(k=0;k<size;++k)
				if(arr[rowInx][k]==0)
				{
					arr[rowInx][k]=a[j];
					break;
				}
			
		}
		for(j=0;j<10;++j)
		{
			for(k=0;k<size;++k)
			{
				if(arr[j][k]==0)
					break;
				a[inx++]=arr[j][k];
				arr[j][k]=0;
			}
		}
		inx=0;
		
	}
}
int main()
{
	int narr[]={278,109,63,930,589,184,505,269,8,83};
	CountSort(narr,10);
	for(int i=0;i<10;++i)
		cout<<narr[i]<<" ";
	cout<<endl;
	return 0;
}