//mergeSort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int countbest, countavg;

void Merge(int a[], int l, int m, int r, int type)
{
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i=0;i<n1;i++)
        L[i] = a[l+i];
    for(j=0;j<n2;j++)
        R[j]=a[m+1+j];
        
    i=0;
    j=0;
    k=l;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
        if(type==1)
            countbest++;
        else
            countavg++;
    }

    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
}


void mergeSort(int a[], int l, int r, int type)
{
    if(l<r)
    {
        int m= l + (r-l) / 2;
        mergeSort(a,l,m,type);
        mergeSort(a,m+1,r,type);
        Merge(a,l,m,r,type);
    }
}



int main()
{
    int n, *best, *avg;
    FILE *bestms, *avgms;
    system("rm bestms.txt");
    system("rm avgms.txt");

    bestms = fopen("bestms.txt", "a");
    avgms = fopen("avgms.txt", "a");

    for(n=10;n<=100;n=n+10)
    {
        countbest = 0;
        countavg = 0;
        best = (int*) malloc(n*sizeof(int));
        avg = (int*) malloc(n*sizeof(int));

        srand(time(0));
        for(int i=0;i<n;i++)
        {
            best[i] = i + 1;
            avg[i] = rand()%1000;
        }

        mergeSort(best, 0, n-1 ,1);
        mergeSort(avg, 0, n-1, 0);

        fprintf(bestms, "%d  %d\n", n , countbest);
        fprintf(avgms, "%d  %d\n", n, countavg);
    }

    fclose(bestms);
    fclose(avgms);

    return 0;
}