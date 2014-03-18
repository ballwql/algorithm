#include <stdio.h>
#include <stdlib.h>
/*
//common method:
int main()
{
	int N,i,j,count=0;
	printf("Input the N: ");
	scanf("%d",&N);
	int *pN=NULL;
	pN=new int[N];
	for(i=0;i<N;++i)
		pN[i]=i;
	for(i=0,j=0;i<N;i=(i+1)%N)
	{
		if(pN[i]!=-1)
		{
			j++;
			if(j%3==0)
			{
				pN[i]=-1;
				count++;
				if(count==N)
				{
					printf("the last people is %d\n",i);
					break;
				}
			}
		}

	}
	return 0;
}
*/
//recursive formula, 
int main()
{
    int N, i, s = 0;

    printf("Please enter the number of people(N): ");
    scanf("%d", &N);

    for (i = 2; i <= N; i++)
    {
        s = (s + 3) % i;
    }
    printf ("The last people is %d\n", s);

    return 0;
}