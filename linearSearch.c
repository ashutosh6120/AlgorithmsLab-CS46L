//LINEAR SEARCH PROGRAM

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
  
int main()
{
    int a[10],i,key;
    printf("Enter array elements: ");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
     
    printf("\nEnter element to search: ");
    scanf("%d",&key);
     
    for(i=0;i<10;i++)
        if(a[i]==key)
            break;
     
    if(i<10)
        printf("\nElement found at position %d\n",i+1);
    else
        printf("\nElement not found in the list\n");
  
    return 0;
}
