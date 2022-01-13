#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
//const
const int MAX_N = 500005;
const int MAX_M = 500005;
const int INF = 1 << 30;
//input
int N, M;
int S[MAX_M], T[MAX_M];
int dp[MAX_N];

//セグメント木の関数
int n;
int dat[MAX_N];
void init(int n_){
    n = 1;
    while (n < n_) n *= 2;
    for (int i=0;i<2 * n - 1;i++) dat[i] = INF;
}

void update(int k, int a){
    k += n - 1;
    dat[k] = a;
    while (k > 0){
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

int query(int a, int b, int k, int l, int r){
    //範囲外
    if (r <= a || b <= l) return INF;

    if (a <= l && r <= b) return dat[k];

    else{
        int v1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(v1, v2);
    }
}


int main(){
    //cin >> N >> M;
    // for (int i=0;i<M;i++){
    //     cin >> S[i] >> T[i];
    //     //S[i]--;
    // }

    scanf("%d %d", &N, &M);
    for (int i=0;i<M;i++){
        scanf("%d %d", &S[i], &T[i]);
    }
    init(N);
    for (int i=0;i<=N;i++){
        dp[i] = INF;
    }
    dp[1] = 0;
    update(1, 0);
    for (int i=0;i<M;i++){
        int v = min(dp[T[i]], query(S[i], T[i] + 1, 0, 0, n) + 1);
        dp[T[i]] = v;
        update(T[i], v);
    }

    // for (int i=0;i<=N;i++){
    //     cout << dp[i] << endl;
    // }
    cout << dp[N] << endl;
    return 0;
}
