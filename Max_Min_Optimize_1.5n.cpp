#include <iostream>
using namespace std;
//1.5n次比较同时找最大最小，如果一般的比较最小涉及2n次比较
void find_max_min(int a[],int size)
{
	int i=0;
	int nhalf=size>>1;
	int min=0,max=0;
	if((size&1))
	{
		if(a[0]>a[size-1])
			swap(a[0],a[size-1]);
		
	}
	for(i=0;i<nhalf;++i)
		if(a[i]>a[i+nhalf])
			swap(a[i],a[i+nhalf]);
	
	min=a[0];
	for(i=1;i<nhalf;++i)
		if(a[i]<min)
			min=a[i];
	max=a[nhalf];
	for(i=nhalf+1;i<size;++i)
		if(a[i]>max)
			max=a[i];
	cout<<"max="<<max<<", min="<<min<<endl;
}
int main()
{
	int a[]={12,4,28,9,54,22,63};
	find_max_min(a,7);
	return 0;
}