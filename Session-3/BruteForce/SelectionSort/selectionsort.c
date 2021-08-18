//selectionSort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int selectionSort(int a[], int n)
{
    int i,j,min,temp,count=0;
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            count++;
            if(a[j] < a[min])
            {
                min = j;
            }
        }
        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
    return count;
}

int main()
{
    int n, countbest, countavg, countworst, num, *best, *avg, *worst;
    FILE *bestss, *worstss, *avgss;
    system("rm bestss.txt");
    system("rm worstss.txt");
    system("rm avgss.txt");

    bestss = fopen("bestss.txt", "a");
    worstss = fopen("worstss.txt", "a");
    avgss = fopen("avgss.txt","a");

    for(n=10;n<=100;n=n+10)
    {
        countbest=0;
        countavg=0;
        countworst=0;

        best = (int*) malloc(n*sizeof(int));
        worst = (int*) malloc(n*sizeof(int));
        avg = (int*) malloc(n*sizeof(int));
        srand(time(0));
        num = rand()%1000;

        for(int i=0;i<n;i++)
        {
            best[i]=i+1;
            worst[i]=num-i;
            avg[i]=rand()%1000;
        }
        countbest=selectionSort(best,n);
        countworst=selectionSort(worst,n);
        countavg=selectionSort(avg,n);

        fprintf(bestss,"%d  %d\n",n, countbest);
        fprintf(worstss,"%d  %d\n",n, countworst);
        fprintf(avgss,"%d  %d\n",n, countavg);
    }

    fclose(bestss);
    fclose(worstss);
    fclose(avgss);
    return 0;
}