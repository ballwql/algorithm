#include <iostream>

using namespace std;
const int N=10;
class T
{
private:
	int top[N];
	int bottom[N];
	bool success;
public:
	T();
	int *getBottom();
	void setNextBottom();
	int getFrequecy(int num);
};
T::T()
{
	success=false;
	for(int i=0;i<N;++i)
		top[i]=i;
}
int* T::getBottom()
{
	int i=0;
	while(!success)
	{
		i++;
		setNextBottom();

	}
	return bottom;
}
void T::setNextBottom()
{
	bool reB=true;
	for(int i=0;i<N;++i)
	{
		int frequecy=getFrequecy(i);
		if(bottom[i]!=frequecy)
		{
			bottom[i]=frequecy;
			reB=false;
		}
	}
	success=reB;
}
int T::getFrequecy(int num)
{
	int count=0;
	for(int i=0;i<N;++i)
	{
		if(bottom[i]==num)
			count++;
	}
	return count;
}
int main()
{
	T nTb;
	int *result=nTb.getBottom();
	for(int i=0;i<N;++i)
		cout<<*result++<<endl;
	return 0;
}