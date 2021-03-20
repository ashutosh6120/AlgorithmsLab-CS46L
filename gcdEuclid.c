//GCD EUCLID'S Program !!!

#include<stdio.h>
int main()
{
    int m,n,r;
    printf("enter m and n values:\n");
    scanf("%d%d",&m,&n);
    while(n != 0) {
        r = m % n;
        m = n;
        n = r;
    }
    printf("\ngcd of given two integers %d\n", m);
}
