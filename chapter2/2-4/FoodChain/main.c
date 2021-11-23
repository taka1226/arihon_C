#include <stdio.h>
#include <stdbool.h>

//const
#define MAX_N 50001

int par[3 * MAX_N]; // 親
int treeRank[3 * MAX_N]; // 木の深さ
int N, K;

//n要素で初期化
void init(int n){
    for (int i=1;i<=n;i++){
        par[i] = i;
        treeRank[i] = 0;
    }
}

//木の根を求める
int find(int x){
    if (par[x] == x){
        return x;
    }else{
        return par[x] = find(par[x]);
    }
}

//xとyの属する集合を併合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y) return;
    if (treeRank[x] < treeRank[y]){
        par[x] = y;
    }else{
        par[y] = x;
        if (treeRank[x] == treeRank[y])treeRank[x]++;
    }
}

//xとyが同じ集合に属するか
bool same(int x, int y){
    return find(x) == find(y);
}

int main(){
    scanf("%d %d", &N, &K);

    //初期化
    init(3 * N);

    int type, x, y;
    int cnt;
    for (int i=0;i<K;i++){
        scanf("%d %d %d", &type, &x, &y);
        if (x <= 0 || N < x || y <= 0 || N < y){
            cnt++;
            continue;
        }
        if (type == 1){
            if (!same(x, y + N) && !same(x, y + 2 * N) && !same(x + N, y + 2 * N) && !same(x + N, y) && !same(x + 2 * N, y) && !same(x + 2 * N, y + N)){
                unite(x, y);
                unite(x + N, y + N);
                unite(x + 2 * N, y + 2 * N);
            }else{
                cnt++;
            }
        }else if (type == 2){
            if (!same(x, y + 2 * N) && !same(x, y) && !same(x + N, y) && !same(x + N, y + N) && !same(x + 2 * N, y + N) && !same(x + 2 * N, y + 2 * N)){
                unite(x, y + N);
                unite(x + N, y + 2 * N);
                unite(x + 2 * N, y);
            }else{
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}
