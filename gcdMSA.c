//GCD using middle school algorithm

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int Prime(int [], int);
int GCD(int [], int [], int, int);


void main()
{
    int m,n;
    printf("enter two numbers to find gcd: ");
    scanf("%d%d",&m,&n);
    int num1[100], num2[100];
    int a1 = Prime(num1, m);
    int a2 = Prime(num2, n);
    for(int i = 0; i < a1; i++)
	printf("\n%d", num1[i]);
	printf("\nGCD is %d\n", GCD(num1, num2, a1, a2));
}

int Prime(int X[], int x)
{
    int i =0, count = 0;
    while(x % 2 == 0){
	X[i] = 2;
	x = x / 2;
	i++;
	count++;
    }
    int c = sqrt(x);
    for(int j = 3; j<= x; j = j+2) {
	while(x % j == 0) {
	     X[i] = j;
	     x = x / j;
	     i++;
	     count++;
        }
    }
    return count;
}


int GCD(int num1[], int num2[], int a1, int a2)
{
    int gcd = 1;
    for(int i=0; i< a1; i++) {
	for(int j=0; j< a2; j++){
	     if(num1[i] == num2[j])
	     {
		gcd = gcd * num1[i];
		num2[j] = 0;
		i++;
	     }
	}
    }
    return gcd;
}
