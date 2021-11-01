#include <stdio.h>
#include <stdbool.h>

int M[21];
int n, k;

bool dfs(int i, int sum){
    if (i == n) return sum == k;
    if (dfs(i+1, sum)) return true;
    if (dfs(i+1, sum + M[i])) return true;

    return false;
}

int main(){
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%d", &M[i]);
    }
    scanf("%d", &k);

    bool ans = dfs(0, 0);

    return 0;
}
