/*Find complete number,for example:6=1+2+3,(1,2,3) are the factor of 6,
  Note: complete number must be an even number,so when traversing ,increment can be 2*/
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int factor_sum(int n)
{
	int sum=1;
	int bn=n/2;
	for(int i=2;i<=bn;++i)
		if(n%i==0)
			sum=sum+i;
	return sum;
}
int main()
{
	int num,n;
	while(cin>>n)
	{
	    cout<<n<<": ";
		for(num=2;num<=n;num+=2) //num must be an even number,so increment is 2,
		{
		    
			if(num==factor_sum(num)) 
			cout<<num<<" ";
		}
		cout<<endl;
	}
	return 0;
}