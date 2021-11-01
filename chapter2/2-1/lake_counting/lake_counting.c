#include <stdio.h>

#define MAX_M 100
#define MAX_N 100

char field[MAX_N][MAX_M];
int N, M;

//(x, y) は自分が今いる位置
void dfs(int x, int y){
    field[x][y] = '.';

    for (int dx=-1;dx<=1;dx++){
        for (int dy=-1;dy<=1;dy++){
            int nx = x + dx;
            int ny = y + dy;

            if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W'){
                dfs(nx, ny);
            }
        }
    }

    return;
}

int main(){
    scanf("%d %d\n", &N, &M);
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            scanf("%c", &field[i][j]);
        }
        if (i < N - 1)
            scanf("\n");
    }

    int res = 0;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            if (field[i][j] == 'W'){
                dfs(i, j);
                res++;
            }
        }
    }

    printf("%d\n", res);

    return 0;

}
