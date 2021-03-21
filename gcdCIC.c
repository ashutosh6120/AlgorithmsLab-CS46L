//gcd using consecutive integer checking algorithm

#include<stdio.h>
#define MIN(a,b) (((a) < (b)) ? (a):(b))

int gcd(int a, int b)
{
	int t,t1,t2;
	t = MIN(a,b);
	while(t != 1)
	{
		t1 = a % t;
		if(t1 == 0){
			t2 = b % t;
			if(t2 == 0)
				return t;
		}
	t = t - 1;
	}
}


int main()
{
	int a,b;
	printf("enter 2 numbers a and b: \n");
	scanf("%d%d",&a,&b);
	int x = gcd(a,b);
	printf("\n%d is the gcd of two nos\n",x);
	return 0;
}
