#include <stdio.h>

#define MAX_N 101
#define MAX_W 10001
int N, W;

int max(int a, int b);
void solve();

typedef struct Pair Pair;
struct Pair {
    int w;  //重量
    int v;  //価値
};

Pair items[MAX_N];

int dp[MAX_N][MAX_W];

int max(int a, int b){
    if (a > b) return a;
    return b;
}
void solve(){
    for (int i=0;i<N;i++){
        for (int j=1;j<=W;j++){
            if (j < items[i].w){
                dp[i+1][j] = dp[i][j];
            }else{
                dp[i+1][j] = max(dp[i][j], dp[i+1][j - items[i].w] + items[i].v);
            }
        }
    }
}

int main(){
    scanf("%d", &N);
    for (int i=0;i<N;i++){
        scanf("%d %d", &items[i].w, &items[i].v);
    }
    scanf("%d", &W);

    solve();

}
