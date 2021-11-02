#include <iostream>
#include <queue>

using namespace std;

//定数
const int MAX_H = 60;
const int MAX_W = 60;
const int INF = 1000000000;

//入力変数
int H, W;
int sx, sy, gx, gy;
char maze[MAX_H][MAX_W];
int d[MAX_H][MAX_W];

// 移動するベクトル
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


typedef pair<int, int> P;

int bfs(){
    queue<P> que;

    //配列 d の初期化
    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            d[i][j] = INF;
        }
    }

    // スタート地点をキューにいれて、距離を0にする
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    while (que.size()){
        P p = que.front();
        que.pop();

        if (p.first == gx && p.second == gy) break;

        for (int i=0;i<4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];

            if (1 <= nx && nx <=H && 1 <= ny && ny <= W && maze[nx - 1][ny - 1] == '.' && d[nx][ny] == INF){
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }

    return d[gx][gy];
}


int main(){
    std::cin >> H >> W;
    std::cin >> sx >> sy;
    std::cin >> gx >> gy;

    for (int i=0;i<H;i++){
        for (int j=0;j<W;j++){
            std::cin >> maze[i][j];
        }
    }

    //ちゃんと入力できているかとうか
    // for (int i=0;i<H;i++){
    //     for (int j=0;j<W;j++){
    //         std::cout << maze[i][j];
    //     }
    //     printf("\n");
    // }
    //

    int ans = bfs();
    printf("%d\n", ans);

    return 0;

}
