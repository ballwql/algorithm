#include <stdio.h>
#include <string.h>
#define MAX_LEN 150 //define the max size of result array

int main()
{
	unsigned int aResult[MAX_LEN+10]; //store the result
	unsigned int an[7];  //store the input string as interger type
	char s[7];  //input string (float), occupy 1 to 6 column
	int n;  // input integer, occupy 1 column
	int i,j,k,tmpN,dotPos;
	bool startFlag=false;
	unsigned tmpResult[MAX_LEN+10]; // temporatory result save
	
	while(scanf("%s%d",s,&n)==2) //judge whether the number of input parameters is 2 or not
	{		
		memset(an,0,sizeof(an));  //initialize
		memset(aResult,0,sizeof(aResult)); //initialize 
		memset(tmpResult,0,sizeof(tmpResult));
		int nLen=strlen(s);
		if(nLen<1 || nLen>6) //get rid of illegal input string
			return 0;
		if(n<=0 || n>25)  //get rid of illegal input integer
			return 0;
		j=0;
		dotPos=0;
		for(i=nLen-1;i>=0;--i){ //transform the string to int array
			if(s[i]!='.')
				an[j++]=s[i]-'0';
			else
			{
				dotPos=nLen-i-1; //record the position of decimal 
			}
		}
		
		for(i=0;i<j;++i)  //initialize the result array as the input float number
			aResult[i]=an[i];
		k=j;
		tmpN=n;
		while(tmpN!=1) //
		{
			
			for(i=0;i<nLen-1;++i)
			{
				for(j=0;j<MAX_LEN;++j)
					tmpResult[i+j]+=an[i]*aResult[j]; //loop multiply
			}	

			memset(aResult,0,sizeof(aResult));
			//deal with carry at last
			for(i=0;i<MAX_LEN;++i){
				if(tmpResult[i]>=10){
					tmpResult[i+1]+=tmpResult[i]/10;
					tmpResult[i]=tmpResult[i]%10;
				}
				aResult[i]=tmpResult[i];
			}
			
			memset(tmpResult,0,sizeof(tmpResult));
			tmpN--;
			
		}		
		tmpN=dotPos*n-1;
		k=0;
		//deal with the suffix "0" 
		for(i=0;i<MAX_LEN && !aResult[i];++i)
			k++;
		for(i=MAX_LEN-1;i>=k;i--)
		{
			if(i>tmpN && aResult[i]) //deal with the prefix "0"
				startFlag=true;
			if(i==tmpN)  //locate the decimal point 
			{
				if(startFlag==false)
					startFlag=true;
				printf(".");
			}
			//print the result
			if(startFlag==true)
				printf("%d",aResult[i]);
		}		
		printf("\n");
		startFlag=false;	//reset again
		
	}
	return 0;
}