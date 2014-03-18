#include <iostream>
using namespace std;
//move the last m characters of string to the beginning of string, just like right rotate string
void reverse(char* str,int m)
{
	int i=0;
	int len=strlen(str);
	
	char *p=NULL,*q=NULL;
	p=str;
	q=str+len-m-1;
	
	while(p<q)
		swap(*p++,*q--);
	p=str+len-m;
	q=str+len-1;
	while(p<q)
		swap(*p++,*q--);
	p=str;
	q=str+len-1;
	while(p<q)
		swap(*p++,*q--);


}
int main()
{
	char s[]="Ilovebaofeng";
	reverse(s,7);
	cout<<s<<endl;
	return 0;
}