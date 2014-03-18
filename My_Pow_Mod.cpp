#include <iostream>
using namespace std;
//快速求幂
int mypow(int base, int x)
{
	int r=1;
	while(x)
	{
		if(x&1)
			r*=base;
		base*=base;
		x>>=1;
	}
	return r;
}
//快速求幂取模
int mypow_mod(int base,int x, int m)
{
	int r=1;
	while(x)
	{
		if(x&1)
			r=(r*base)%m;
		base=(base*base)%m;
		x>>=1;
	}
	return r;
}
int main()
{
	int i=-1;
	cout<<mypow(2,5)<<endl;
	cout<<mypow_mod(2,5,3)<<endl;
	return 0;
}