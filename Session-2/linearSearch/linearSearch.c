//Linear Search program.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int a[50000], searchbest, searchworst, searchavg, i;
    FILE *b, *w, *avg;
    system("rm bestls.txt");
    system("rm worstls.txt");
    system("rm avgls.txt");
    srand(time(0));


    for(i = 0; i < 1000; i++)
    {
        a[i] = rand() % 1000;
    }

    for(int n=10; n<=100; n=n+10)
    {
        int countbest=0;
        int countavg=0;
        int countworst=0;
        b = fopen("bestls.txt", "a");
        avg = fopen("avgls.txt", "a");
        w = fopen("worstls.txt", "a");
        searchbest=a[0];
        searchavg=a[(n/2)];
        searchworst=rand()%10000;
        
        //BEST-CASE
        for(i=0;i<n;i++)
        {
            countbest++;
            if(a[i]==searchbest)
            {
                break;
            }
        }

        //AVERAGE-CASE
        for(i=0;i<n;i++)
        {
            countavg++;
            if(a[i]==searchavg)
            {
                break;
            }
        }

        //WORST-CASE
        for(i=0;i<n;i++)
        {
            countworst++;
            if(a[i]==searchworst)
            {
                break;
            }
        }

        fprintf(b,"%d\t %d\n", n, countbest);
        fprintf(avg, "%d\t %d\n", n, countavg);
        fprintf(w, "%d\t %d\n", n , countworst);

        fclose(b);
        fclose(avg);
        fclose(w);
    }
}