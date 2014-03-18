#include <iostream>
using namespace std;
const int BYTESIZE=8;
//rules to select bytes:
//1.find max num from specified number sequence
//2.num of bytes = (max_num/8)+1
void setbit(char* p, int posi)
{
	int i=0;
	for(i=0;i<posi/BYTESIZE;++i)
		p++;
	*p=*p|(0x01<<(posi%BYTESIZE));
}

int main()
{
	int buflen=2;
	char* pBuf=new char[buflen];
	memset(pBuf,0,sizeof(char)*buflen);
	int a[]={15,4,7,9,12,8,3,13,2}; //use 2 bytes to store, 
	int i=0,j=0;
	for(i=0;i<9;++i)
		setbit(pBuf,a[i]);
		
	for(i=0;i<buflen;++i)
	{
		for(j=0;j<BYTESIZE;++j)
		{
			if((*pBuf&(0x01<<j))==0x01<<j)
				printf("%d ",i*BYTESIZE+j);
		}
		pBuf++;
	}
	return 0;
}