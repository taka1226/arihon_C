#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_N 10000
#define INF 10000000

//入力される値
int n, k;
int w[MAX_N], v[MAX_N];

double S[MAX_N];  //vi - x * wi の値を格納する

//降順
int cmpnum(const void * n1, const void * n2)
{
        if (*(double *)n1 < *(double *)n2)
        {
                return 1;
        }
        else if (*(double *)n1 > *(double *)n2)
        {
                return -1;
        }
        else
        {
                return 0;
        }
}

bool possible(double x){
    for (int i=0;i<n;i++){
        S[i] = v[i] - x * w[i];
    }

    //降順にソード
    qsort(S, n, sizeof(double), cmpnum);

    double sum = 0;
    for (int i=0;i<k;i++){
        sum += S[i];
    }

    return sum >= 0;
}

int main(){
    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++){
        scanf("%d %d", &w[i], &v[i]);
    }

    double lb = 0;
    double rb = INF;
    double mid;

    for (int i=0;i<100;i++){
        mid = (lb + rb) / 2;
        if (possible(mid)){
            lb = mid;
        }else{
            rb = mid;
        }
    }

    printf("%lf\n", rb);
    return 0;
}
