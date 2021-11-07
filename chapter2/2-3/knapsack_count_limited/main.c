// https://algo-method.com/tasks/313

#include <stdio.h>

#define MAX_N 505
#define MAX_K 100005

//入力
int n, k;
int a[MAX_N], m[MAX_N];

// dp
int dp[MAX_N][MAX_K];

int main(){
    scanf("%d %d", &n, &k);
    for (int i=0;i<n;i++){
        scanf("%d %d", &a[i], &m[i]);
    }

    //dp の初期化
    for (int j=1;j<=k;j++){
        dp[0][j] = -1;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<=k;j++){
            if (dp[i][j] >= 0){
                dp[i + 1][j] = m[i];
            }else if (j < a[i] || dp[i + 1][j - a[i]] <= 0){
                dp[i + 1][j] = -1;
            }else{
                dp[i + 1][j] = dp[i + 1][j - a[i]] - 1;
            }
        }
    }


    if (dp[n][k] >= 0){
        printf("Yes\n");
    }else{
        printf("No\n");
    }


    return 0;


}
