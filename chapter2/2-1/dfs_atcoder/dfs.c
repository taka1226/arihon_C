#include <stdio.h>
#include <stdbool.h>

#define MAX_H 510
#define MAX_W 510

char field[MAX_H][MAX_W];

int H, W;
int vx[4] = {0, 1, 0, -1};
int vy[4] = {-1, 0, 1, 0};

bool ans = false;

void dfs(int x, int y){
    field[x][y] = 't';
    for (int i=0;i<4;i++){
        int nx = x + vx[i];
        int ny = y + vy[i];

        if (0 <= nx && nx < H && 0 <= ny && ny < W){
            if (field[nx][ny] == '.'){
                dfs(nx, ny);
            }

            if (field[nx][ny] == 'g'){
                ans = true;
                return;
            }
        }
    }

}


int main(){
    scanf("%d %d\n", &H, &W);
    int start_x, start_y;
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            scanf("%c", &field[i][j]);
            if (field[i][j] == 's'){
                start_x = i;
                start_y = j;
            }
        }
        if (i < H - 1)
            scanf("\n");
    }

    dfs(start_x, start_y);

    if (ans)
        printf("Yes\n");
    else
        printf("No\n");


}
