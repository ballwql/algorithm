#include <iostream>
#include <string>
using namespace std;
int my_atoi(const char* src)
{
	const char* p=src;
	int tmp=0,k=0;
	int *pBit=new int[strlen(src)+1];
	
	
	while(*p)
	{
		if(*p<'0'||*p>'9')
			return -1;
		
		pBit[k++]=*p-'0';
		p++;
	}
	
	for(int i=0;i<k;++i)
		tmp=tmp*10+pBit[i];
	return tmp;
}
void my_itoa(const int data,char* dest,int size)
{
	int i=0,k=0;
	int tData=data;
	if(data<0)
	{
		dest[0]='-';
		i++;
		k++;
	}
	do
	{
		dest[i++]=tData%10+'0';
		tData/=10;
	}while(tData);
	dest[i]='\0';
	
	for(;k<i/2;++k)
	{
		char tc=dest[k];
		dest[k]=dest[i-k-1];
		dest[i-k-1]=tc;
	}

}
int main()
{
	cout<<my_atoi("123")<<endl;
	return 0;
}