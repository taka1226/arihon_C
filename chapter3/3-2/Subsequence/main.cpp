#include<bits/stdc++.h>
using namespace std;

//input
int N, S;
int A[5000];
int T[5005];

int main(){
    cin >> N >> S;
    for (int i=0;i<N;i++){
        cin >> A[i];
    }

    int sum = 0;
    for (int i=0;i<N;i++){
        T[i+1] = T[i] + A[i];
    }
    //累積和を計算
    // for (int i=1;i<=N;i++){
    //     cout << T[i] << endl;
    // }

    int r = 0;
    int ans = 100000;
    for (int l=0;l<N;l++){
        while (T[r] - T[l] < S && r < N){
            r++;
        }
        if (T[r] - T[l] < S) break;
        ans = min(ans, r - l);
    }

    cout << ans << endl;

    return 0;
}
