#include <stdio.h>
#include <string.h>


#define MAX_N 2000
#define MAX_M 2000
#define MAX_Q 151

char s[MAX_N];
char t[MAX_M];
int dp[MAX_N][MAX_M];
int n, m;

int max(int a, int b);
int lcs(int i, int j);

int max(int a, int b){
    if (a > b) return a;

    return b;
}


// iはSの何番目か, jはTの何番目か
int lcs(int i, int j){
    if (dp[i][j] >= 0){
        //すでに調べたことがあるならその結果を利用
        return dp[i][j];
    }
    int res;
    if (i == 0 || j == 0) res = 0;
    else if (s[i - 1] == t[j - 1]){
        res = max(lcs(i - 1, j - 1) + 1, max(lcs(i, j - 1), lcs(i - 1, j)));
    }else{
        res = max(lcs(i, j - 1), lcs(i - 1, j));
    }

    return dp[i][j] = res;
}

int main(){
    int q;
    scanf("%d", &q);

    int ans[MAX_Q];
    for (int i=0;i<q;i++){
        //dp を初期化
        memset(dp, -1, sizeof(dp));

        scanf("%s", s);
        scanf("%s", t);
        n = strlen(s);
        m = strlen(t);
        ans[i] = lcs(n, m);
    }

    for (int i=0;i<q;i++){
        printf("%d\n", ans[i]);
    }


    return 0;
}
