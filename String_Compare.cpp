#include <iostream>
#include <algorithm>
using namespace std;
int partition(string &str, int lo,int hi)
{
	int key=str[hi];
	int i=lo-1;
	for(int j=lo;j<hi;++j)
	{
		if(str[j]<key)
		{
			i=i+1;
			swap(str[i],str[j]);
		}
	}
	swap(str[i+1],str[hi]);
	return i+1;
}
void quicksort(string &str, int lo,int hi)
{
	if(lo<hi)
	{
		int pivot=partition(str,lo,hi);
		quicksort(str,lo,pivot-1);
		quicksort(str,pivot+1,hi);
	}
}
//check all of characters of str2 are existed in str1 or not, 
bool compare(const string& str1, const string& str2) 
{
	int i=0,j=0;
	int len1=str1.length();
	int len2=str2.length();
	while(i<len1&&j<len2)
	{
		while(str1[i]<str2[j] && i<len1)
			i++;
		if(str1[i]!=str2[j]) //means str1[i]>str2[j]: str2[j] not exist in str1
			break;
		j++;
	}
	if(j==len2)
		return true;
	return false;
}
int main()
{
	string str1="ABCDEFGHLMNOPQRS";
	string str2="DCGDSRQPOM";
	quicksort(str1,0,str1.length()-1);
	quicksort(str2,0,str2.length()-1);
	if(compare(str1,str2))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}