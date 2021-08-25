//quicksort

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int countavg;
int countworst;

int Partition(int A[], int start, int end, int type) {
    int temp;
    int i = start + 1;
    int piv = A[start];
    for(int j = start +1; j<=end; j++) {
        if(A[j] > piv) {
            if(type == 1)
                countavg++;
            if(type == 2)
                countworst++;
            
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;

            i+=1;
        }
    }
    temp = A[start];
    A[start] = A[i-1];
    A[i-1] = temp;
    return i-1;
}


void QuickSort(int a[], int l, int r, int type) {
    int p;
    if(l < r) {
        p = Partition(a,l,r,type);
        QuickSort(a,l,p - 1, type);
        QuickSort(a,p + 1, r, type);
    }
}


int main() {
    int n, *avg, *worst;
    FILE *avgqs, *worstqs;
    system("rm avgqs.txt");
    system("rm worstqs.txt");

    avgqs = fopen("avgqs.txt", "a");
    worstqs = fopen("worstqs.txt", "a");

    for(n=10; n<=100; n=n+10) {
        countavg = 0;
        countworst = 0;
        avg = (int*)malloc(n * sizeof(int));
        worst = (int*)malloc(n * sizeof(int));
        srand(time(0));
        for(int i=0;i<n;i++) {
            avg[i] = rand() % 1000;
            worst[i] = i - 1;
        }
        QuickSort(avg,0,n - 1, 1);
        QuickSort(worst,0,n-1,2);

        fprintf(avgqs, "%d %d\n", n, countavg);
        fprintf(worstqs, "%d %d\n", n, countworst);
    }

    fclose(avgqs);
    fclose(worstqs);

    return 0;
}