#include <iostream>
#include <string>
using namespace std;
char hexChr[100];
void chartohex(const char* src)
{
    const char* p=src;
	const char hex_map[17]="0123456789ABCDEF";
	int i=0;
	int k=0;
	int tmp=0;
	while(*p)
	{
		if(*p>='0'&&*p<='9')
			tmp=(*p-'0')+48;
		else if(*p>='a'&&*p<='z')
			tmp=(*p-'a')+96;
		else if(*p>='A'&&*p<='Z')
			tmp=(*p-'A')+65;
		hexChr[k++]=tmp/16+'0';			
		hexChr[k++]=hex_map[tmp%16];
		p++;
	}
	hexChr[k]='\0';
	cout<<hexChr<<endl;	
}
int main()
{
	chartohex("abcdef");
	return 0;
}