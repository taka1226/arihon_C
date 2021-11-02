#include <stdio.h>


#define MAX_N 110
int N, W;

typedef struct Pair Pair;
struct Pair {
    int v;  //価値
    int w;  //重さ
};

Pair items[MAX_N];

int max(int a, int b);
int naive(int i, int j);

int max(int a, int b){
    if (a > b) return a;
    else
        return b;
}

//iの品物で重さの総和がj をこえないようにする
int naive(int i, int j){
    int res;
    if (i == N){
        //もう品物は残っていない
        res = 0;
    }else if (items[i].w > j){
        res = naive(i + 1, j);
    }else{
        res = max(naive(i + 1, j), naive(i + 1, j - items[i].w) + items[i].v);
    }
    return res;
}

int main(){
    scanf("%d %d", &N, &W);
    for (int i=0;i<N;i++){
        scanf("%d %d", &items[i].v, &items[i].w);
    }

    int ans = naive(0, W);
    printf("%d\n", ans);

    return 0;

}
