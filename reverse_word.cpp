#include <iostream>
#include <string>
using namespace std;
void swap(char &c1, char &c2)
{
	char tmp=c1;
	c1=c2;
	c2=tmp;
}
char* reverse_word(char* str)
{
	char *p,*q,*start,*end;
	if(NULL==str)
		return NULL;
	p=start=end=str;
	while(*p++!='\0')
	{
		if(*p==' ' || *p=='\0')
		{
			while(start<end)
				swap(*start++,*end--);	
			start=end=p+1;
			continue;
		}
		end=p;
	}
	start=str;
	end=p-2;
	while(start<end)
		swap(*start++,*end--);
	return str;
}
int main()
{
	char carr[]="I am student";
	cout<<reverse_word(carr)<<endl;
	return 0;
}