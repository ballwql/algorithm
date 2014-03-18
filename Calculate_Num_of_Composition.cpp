#include <iostream>
using namespace std;
/*
Note: one person go from a stair with n steps, three ways to go: 1 step per time, 2 steps per time, or 3 steps per time
how many ways he can go through the stair
*/
int solve(int n)
{
	int maxStep1,maxStep2,maxStep3;
	int cnt=0;
	maxStep1=n/5+1; // way of 3 steps per time
	for(int i=0;i<maxStep1;++i)
	{
		maxStep2=(n-i*5)/2+1;
		for(int j=0;j<maxStep2;++j)
		{
			maxStep3=(n-i*5-j*2)/1;
			if(maxStep1 || maxStep2 || maxStep3)
			{
			    cnt++;
			//	printf("%d %d %d\n",i,j,maxStep3);
			}
		}
	}
	return cnt;
}
int main()
{
	int cnt;
	cnt=solve(10);
	cout<<cnt<<endl;
	return 0;
}