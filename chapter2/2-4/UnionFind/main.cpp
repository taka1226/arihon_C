#include <iostream>
using namespace std;

//const
const int MAX_N = 20;

int par[MAX_N]; // 親
int treeRank[MAX_N]; // 木の深さ

//n要素で初期化
void init(int n){
    for (int i=0;i<n;i++){
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
    init(4);
    unite(0, 2);
    unite(1, 3);

    for (int i=0;i<4;i++){
        cout << par[i] << endl;
    }


    return 0;
}
