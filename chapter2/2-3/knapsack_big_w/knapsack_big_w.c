#include <stdio.h>
#include <string.h>

#define MAX_N 101
#define MAX_V 100000
#define INF 10000

typedef long long ll;

int N, W, V; //Vはあたえられた商品の価値を全部足した値
ll dp[MAX_N][MAX_V];
ll w[MAX_N];
int v[MAX_N];

//関数
ll min(ll a, ll b);

ll min(ll a, ll b){
    if (a < b) return a;
    else
        return b;
}

int main(){
    scanf("%d", &N);
    V = 0;
    for (int i=0;i<N;i++){
        scanf("%d %d", &w[i], &v[i]);
        V += v[i];
    }
    scanf("%d", &W);

    //dpの初期化
    for (int i=0;i<N;i++){
        for (int j=0;j<V;j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;

    for (int i=0;i<N;i++){
        for (int j=0;j<V;j++){
            if (j < v[i]) dp[i + 1][j] = dp[i][j];
            else{
                dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
            }
        }
    }

    int ans = 0;
    for (int j=0;j<=V;j++){
        if (dp[N][j] <= W){
            ans = j;
        }
    }

    printf("%d\n", ans);

    return 0;

}
