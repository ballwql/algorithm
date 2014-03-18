/*
* string sort: first, sort by specified key with char sequence, then sort by a-z sequence
* e.g: "helloworld",key:"kol", result: oollldehrw
*/
include <iostream>
using namespace std;
bool isok(const char *skey,char ch)
{
	while(*skey)
	{
		if(*skey==ch)
			return true;
		skey++;
	}
	return false;
}
char* sort_key(const char* src, const char* key)
{
	const char *p=src,*q=key;
	int hash[26]={0};
	int cnt[26]={0};
	int ival=0,ival2=0;
	int len1=strlen(src);
	int i=0,j=0;
	char *dest=new char[len1+1];
	char *t=dest;
	while(*p)
	{
		hash[*p-'a']=++cnt[*p-'a'];	
		
		p++;
	}
	
	while(*q)
	{
		int tcnt=hash[*q-'a'];
		if(tcnt)
		{
			for(i=0;i<tcnt;++i)
				*dest++=*q;
		}
		q++;
	}
	
	for(i=0;i<26;++i)
	{
		int tcnt=hash[i];
		if(false==isok(key,char(i+'a')))
		{
			for(j=0;j<tcnt;++j)
				*dest++=char(i+'a');
		}
	}
	*dest='\0';
	return t;

}
int main()
{
	char *d=sort_key("helloworld","kol");
	cout<<d<<endl;
	return 0;
}