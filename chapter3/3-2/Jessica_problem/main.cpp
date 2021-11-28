#include <iostream>
#include <set>
#include <map>
#include <cstdio>
using namespace std;

typedef long long ll;

//const
const int MAX_P = 1000005;

//input
int P, a[MAX_P];

int main(){
    scanf("%d", &P);
    for (int i=0;i<P;i++){
        scanf("%d", &a[i]);
    }

    set<int>all;
    for (int i=0;i<P;i++){
        all.insert(a[i]);
    }
    int n = all.size();

    map<int, int> count;
    int r = 0;
    int res = P;
    int num = 0;
    for (int l=0;l<P;l++){
        while (r < P && num < n){
            if (count[a[r++]]++ == 0){
                num++;
            }
        }
        if (num < n) break;
        res = min(res, r - l);
        if (--count[a[l]] == 0){
            num--;
        }
    }


    cout << res << endl;

    return 0;
}
