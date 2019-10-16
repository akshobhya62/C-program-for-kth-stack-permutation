#include <stdio.h>
#include <stdlib.h>

long long int binaryNum[2000];

long long int Binary(long long int n)
{
    long long int i = 0;
    long long int k = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    k = i;
    return k;
}

long long int power(long long int a, long long int b)
{
	long long int answer = 1;
	for(long long int i =1;i<=b;i++)
		answer = answer * a;

	return answer;
}


int main()
{
    long long int queries;
    scanf("%lld",&queries);
    while(queries--)
    {
        long long int n,k;
    scanf("%lld%lld",&n,&k);
    long long int final_answer;
    long long int counter =0;
    long long int index = 0;
    long long int initial = 2*(power(2,2*n)-1)/3;
    long long int finals = power(2,n)*(power(2,n)-1);
    for(long long int u =initial;u<=finals;u=u+2)
    {
        if(__builtin_popcount(u)==n)
            {
            long long int wrong = 0;
            long long int upto = Binary(u);
            long long int val = 0;
            for(long long int r =0;r<upto;r++)
            {
                if(binaryNum[r]==1)
                    val++;
                else
                    val--;
                if(val > 0){
                        wrong =1;
                        break;
                }
            }
            if(!wrong)
            {
                index++;
                if(index == k)
                    final_answer = u;

            }
            }
    }

printf("Total number of stack permutations: %lld\n",index);
long long int stack[2*n];
long long int top = -1;
long long int num=1;
long long int x = Binary(final_answer);

printf("kth stack permutation is \n");
for(long long int t = x-1;t>=0;t--)
{
    if(binaryNum[t]==1)
    {
        top++;
        stack[top] =  num;
        num++;
    }
    else if(binaryNum[t]==0)
    {
        printf("%lld ",stack[top]);
        top--;
    }
}

printf("\n");
    }

}

