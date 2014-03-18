//the max sum of sub array:
#include <iostream>
using namespace std;
int main()
{
	int a[]={1,-2,3,10,-4,7,2,-5};
	int maxSum=0,tmpSum=0,bInx=0,eInx=0;
	for(int i=0;i<8;++i)
	{
		if(tmpSum<=0)
		{
			tmpSum=a[i];
			bInx=i; //begin index of sub array
		}
		else
			tmpSum+=a[i];
		if(tmpSum>maxSum)
		{
			maxSum=tmpSum;
			eInx=i; //end index of sub array
		}
	}
	cout<<maxSum<<endl;
	for(i=bInx;i<=eInx;++i)
		cout<<a[i]<<" "; //output sub array
	cout<<endl;
	return 0;
}