#include <stdio.h>

#define MAX_N 1000000

int n, k;
int a[MAX_N];

void solve(){
    //解の存在範囲を初期化
    int lb = -1, ub = n;

    //解の存在範囲が1より大きい場合、繰り返す
    while (ub - lb > 1){
        int mid = (lb + ub) / 2;
        if (a[mid] >= k){
            //midが条件を満たせば。解の存在範囲は(lb, mid]
            ub = mid;
        }else{
            //midが条件をみたさなければ、解の存在範囲は(mid, ub]
            lb = mid;
        }

    }

    //この時点で lb + 1 = ub となっている
    printf("%d\n", ub);
}


int main(){
    scanf("%d", &n);

    for (int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);

    solve();

    return 0;
}
