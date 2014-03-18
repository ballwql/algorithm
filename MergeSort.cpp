#include <iostream>
using namespace std;
void Merge(int a[],int p,int q,int r)
{
	int *tmp=new int[r-p+1];
	memset(tmp,0,(r-p+1)*sizeof(int));
	int i=0,j=0,k=0;
	i=p;
	j=q+1;
	while(i<=q&&j<=r)
	{
		if(a[i]<a[j])
		{
			tmp[k++]=a[i];
			i++;
		}
		else
		{
			tmp[k++]=a[j];
			j++;
		}		
	}
	while(i<=q)
	{
		tmp[k++]=a[i];
		i++;
	}
	while(j<=r)
	{
		tmp[k++]=a[j];
		j++;
	}
	for(i=0;i<k;++i)
		a[p+i]=tmp[i];
	delete []tmp;
}
void MSort(int a[],int p,int r)
{
	if(p<r)
	{
		int mid=p+(r-p)/2;
		MSort(a,p,mid);
		MSort(a,mid+1,r);
		Merge(a,p,mid,r);
	}
}
int main()
{
	int arr[]={49,38,65,97,76,13,27};
	MSort(arr,0,6);
	for(int i=0;i<7;++i)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}