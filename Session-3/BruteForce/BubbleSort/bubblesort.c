//bubblesort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int min, i,j,t,k,b[1000], a[1000], w[1000];
    FILE *bestc, *avgc, *worstc, *bests, *avgs, *worsts;
    system("rm bbestcnt.txt");
    system("rm bavgcnt.txt");
    system("rm bworstcnt.txt");
    system("rm bbestswap.txt");
    system("rm bavgswap.txt");
    system("rm bworstswap.txt");

    for(int n=10; n<=1000; n +=100) {
        bestc = fopen("bbestcnt.txt", "a");
        avgc = fopen("bavgcnt.txt", "a");
        worstc = fopen("bworstcnt.txt", "a");
        bests = fopen("bbestswap.txt", "a");
        avgs = fopen("bavgswap.txt", "a");
        worsts = fopen("bworstswap.txt", "a");
        srand(time(0));
        for(i=0;i<n;i++) {
            b[i] = i + 1;
            w[i] = n - i;
            a[i] = rand() % 1000;
        }

        int countbest=0, bestswap=0;
        for(i=0; i<=n-2; i++) {
            for(j=0; j<= n-2-i; j++) {
                countbest++;
                if(b[j] > b[j+1])
                {
                    bestswap++;
                    t = b[j];
                    b[j] = b[j+1];
                    b[j+1] = t;
                }
            }
        }


        int countavg=0, avgswap=0;
        for(i=0;i<=n-2; i++) {
            for(j=0; j<=n-2-i; j++) {
                countavg++;
                if(a[j] > a[j+1]) {
                    avgswap++;
                    t = a[j];
                    a[j] = a[j+1];
                    a[j+1] = t;
                }
            }
        }

        int countworst=0,worstswap=0;
        for(i=0;i<=n-2;i++) {
            for(j=0;j<=n-2-i;j++) {
                countworst++;
                if(w[j]>w[j+1]) { 
                    worstswap++;
                    t=w[j];
                    w[j]=w[j+1];    
                    w[j+1]=t;
                }
            }
        }

        fprintf(bestc,"%d\t%d\n",n,countbest);
        fprintf(avgc,"%d\t%d\n",n,countavg);
        fprintf(worstc,"%d\t%d\n",n,countworst);
        fprintf(bests,"%d\t%d\n",n,bestswap);
        fprintf(avgs,"%d\t%d\n",n,avgswap);
        fprintf(worsts,"%d\t%d\n",n,worstswap);


        fclose(bestc);
        fclose(avgc);
        fclose(worstc);
        fclose(bests);
        fclose(avgs);
        fclose(worsts);
    }
    
    return 0;
}