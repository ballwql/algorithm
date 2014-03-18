#include <iostream>

using namespace std;
void Heap_Modify(int a[],int index,int length)
{
	int left=index<<1;
	int right=(index<<1)+1;
	int largest = index;
	if(left<length&&a[left]>a[index])
		largest=left;
	if(right<length && a[right]>a[largest])
		largest=right;
	if(largest!=index)
	{
		swap(a[largest],a[index]);
		Heap_Modify(a,largest,length);
	}
}
void Build_max_heap(int a[],int length)
{
	for(int i=length/2;i>=0;--i)
		Heap_Modify(a,i,length);
}
void HeapSort(int a[],int length)
{
	Build_max_heap(a,length);
	for(int i=length-1;i>0;--i)
	{
		swap(a[0],a[i]);
		Heap_Modify(a,0,i);
	}
}
int main()
{
	int arr[]={49,38,65,97,76,13,27,49};
	HeapSort(arr,8);
	for(int i=0;i<8;++i)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
	
}