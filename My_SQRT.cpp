#include <iostream>
#include <map>
#include <string>

using namespace std;

const double EPISON=0.000001;
double MySqrt(double des)
{
	double low=EPISON;
	double high=EPISON;
	double mid=0.0;
	double sqr=0.0;
	high=des>1.0?des:des+1.0;
	do
	{
		mid=(low+high)/2.0;
		sqr=mid*mid;
		if(sqr>des)
			high=mid;
		else
			low=mid;
	}while((sqr-des)<-EPISON || (sqr-des)>EPISON);
	return mid;
}
int main()
{
	double num=0.85;
	cout<<MySqrt(num)<<endl;
	return 0;
}