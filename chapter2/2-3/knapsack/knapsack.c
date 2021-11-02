#include <stdio.h>
#include <string.h>

#define MAX_N 110
#define MAX_W 100001
int N, W;

typedef struct Pair Pair;
struct Pair {
    int v;  //価値
    int w;  //重さ
};

Pair items[MAX_N];
int dp[MAX_N][MAX_W];

int max(int a, int b);
int knapsack(int i, int j);

int max(int a, int b){
    if (a > b) return a;
    else
        return b;
}

//iの品物で重さの総和がj をこえないようにする
int knapsack(int i, int j){
    // すでに調べたことのあるならそれを利用。
    if (dp[i][j] >= 0){
        return dp[i][j];
    }
    int res;
    if (i == N){
        //もう品物は残っていない
        res = 0;
    }else if (items[i].w > j){
        res = knapsack(i + 1, j);
    }else{
        res = max(knapsack(i + 1, j), knapsack(i + 1, j - items[i].w) + items[i].v);
    }
    return dp[i][j] = res;
}

int main(){
    scanf("%d %d", &N, &W);
    for (int i=0;i<N;i++){
        scanf("%d %d", &items[i].v, &items[i].w);
    }

    //dp配列を初期化
    memset(dp, -1, sizeof(dp));

    int ans = knapsack(0, W);
    printf("%d\n", ans);

    return 0;

}
