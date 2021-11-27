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




    return 0;
}
