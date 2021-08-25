//insertionSort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int countbest, countavg, countworst;

void insertionSort(int a[], int n, int type)
{
    int i,key,j;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        if(type==0)
            countbest++;
        if(type==1)
            countavg++;
        if(type==2)
            countworst++;

        while(j>=0 && a[j]>key)
        {
            if(type==0)
                countbest++;
            if(type==1)
                countavg++;
            if(type==2)
                countworst++;
            a[j+1] = a[j];
            j=j-1;
        }
        a[j+1]=key;
    }
}

int main()
{
    int n, *best, *avg, *worst;
    FILE *bestis, *avgis, *worstis;
    system("rm bestis.txt");
    system("rm avgis.txt");
    system("rm worstis.txt");

    bestis = fopen("bestis.txt","a");
    avgis = fopen("avgis.txt","a");
    worstis = fopen("worstis.txt","a");

    for(n=10;n<=100;n=n+10)
    {
        countbest=0;
        countavg=0;
        countworst=0;
        
        best = (int*) malloc(n*sizeof(int));
        avg = (int*) malloc(n*sizeof(int));
        worst = (int*) malloc(n*sizeof(int));

        srand(time(0));

        for(int i=0;i<n;i++)
        {
            best[i] = i +1;
            avg[i] = rand() % 1000;
            worst[i] = n - i;
        }

        insertionSort(best,n,0);
        insertionSort(avg,n,1);
        insertionSort(worst,n,2);

        fprintf(bestis,"%d  %d\n",n,countbest);
        fprintf(avgis, "%d  %d\n",n, countavg);
        fprintf(worstis,"%d  %d\n",n,countworst);
    }

    fclose(bestis);
    fclose(avgis);
    fclose(worstis);
}