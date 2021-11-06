#include <stdio.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>

#define MAX_N 10001
#define INF 10000000000

int N, K;
double L[MAX_N];

// Li の紐から 長さ l を切り出したときの紐の本数が K以上かどうか
bool possible(double l){
    int ans = 0;
    for (int i=0;i<N;i++){
        ans += (int)(L[i] / l);
    }

    return ans >= K;
}


int main(){
    scanf("%d %d", &N, &K);
    for (int i=0;i<N;i++){
        scanf("%lf", &L[i]);
    }

    //二分探索の初期化
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


    printf("%.2f\n", floor(rb * 100) / 100);
    return 0;
}
