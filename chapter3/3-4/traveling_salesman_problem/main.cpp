#include <iostream>
#include <cstring>

using namespace std;

//定数
const int MAX_V = 15;
const int INF = 100000000;

//入力
int V, E;  //頂点と辺の数
int d[MAX_V][MAX_V];

int dp[1 << MAX_V][MAX_V];

// すでに訪れた頂点がS、現在位置がv
int rec(int S, int v){
    if (dp[S][v] >= 0){
        return dp[S][v];
    }

    if (S == (1 << V) - 1 && v == 0){
        //すべての頂点を訪れて戻ってきた
        return dp[S][v] = 0;
    }

    int res = INF;
    for (int u=0;u<V;u++){
        if (!(S >> u & 1)){
            //次にuに移動する
            res = min(res, rec(S | 1 << u, u) + d[v][u]);
        }
    }

    return dp[S][v] = res;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    if (rec(0, 0) >= INF){
        cout << -1 << endl;
    }else{
        cout << rec(0, 0) << endl;
        
    }
}

void debug(){
    //デバッグ
    for (int i=0;i<V;i++){
        for (int j=0;j<V;j++){
            cout << d[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){


    cin >> V >> E;
    //dの初期化
    for (int i=0;i<V;i++){
        for (int j=0;j<V;j++){
            d[i][j] = INF;
        }
    }

    for (int i=0;i<E;i++){
        int s, t, dis;
        cin >> s >> t >> dis;
        d[s][t] = dis;
    }

    //debug();

    solve();
}
