/*
Test whether a number(1-99999) is a symmetrical and prime  number or not

*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
bool isprime(int n)
{
	int sqr=(int)sqrt(n);
	for(int i=2;i<=sqr;++i)
		if(n%i==0)
			return false;
	return true;

}

//test symmetrical number

bool issym(int n)
{
	if(n<12&&n!=10) return true;
	//test a number(100-999)
	if(n>100&&n<1000&&n/100==n%10) return true;
	if(n>10000&&n/1000==n%10*10+n/10%10) return true;

	//if 11<n<99: because 10a+a=11a->is not a prime
	//if 1000<n<9999:because 1000a+100b+10b+a=1001a+101b=11(91a+10b)->is not a prime
	return false;
}

int main()
{
	int num;
	while(cin>>num)
	{
		cout<<(num<100000&&issym(num)&&isprime(num)?"yes\n":"no\n");
	}
	return 0;
}


