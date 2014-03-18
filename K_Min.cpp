#include <iostream>
#include <fstream>

using namespace std;
void Heap_Modify(long a[],int index,int length)
{
	int largest=index;
	int left=2*index;
	int right=2*index+1;
	if(left<length&&a[left]>a[index])
		largest=left;
	if(right<length&&a[right]>a[largest])
		largest=right;
	if(largest!=index)
	{
		long tmp=a[largest];
		a[largest]=a[index];
		a[index]=tmp;
		Heap_Modify(a,largest,length);
	}
}
void Build_Max_Heap(long a[],int length)
{
	for(int i=length/2;i>=0;--i)
		Heap_Modify(a,i,length);
}
void K_Min(long a[],int k)
{
	FILE *fp;
	fp=fopen("data.txt","r");
	if(NULL==fp)
	{
		fprintf(stderr,"fopen() error:%s\n",strerror(errno));
		return;
	}
	int i=0;
	while((i<k)&&fscanf(fp,"%ld",&a[i]) !=EOF)
	{
		i++;
	}
	Build_Max_Heap(a,k);
	long tmp=0;
	
	while(fscanf(fp,"%ld",&tmp)!=EOF)
	{
		
		if(tmp<a[0])
		{
			a[0]=tmp;
			Heap_Modify(a,0,k);
		}
	}
	fclose(fp);
}
int main()
{
	long a[10];
	K_Min(a,4);
	for(int i=0;i<4;++i)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}