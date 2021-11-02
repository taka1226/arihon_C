#include <iostream>
#include <queue>

using namespace std;

const int INF = 100000000;
const int MAX_N = 110;
const int MAX_M = 110;

//状態を表すクラスpairの場合、typedef しておくと便利
typedef pair<int, int>P;

//入力
char maze[MAX_N][MAX_M + 1];
int N, M;
int sx, sy;
int gx, gy;

int d[MAX_N][MAX_M];

// 移動４方向のベクトル
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};



// (sx, xy) から (gx, gy)への最短距離を求める
// たどり着けないとINF
int bfs(){
    queue<P> que;

    //すべての点をINFで初期化
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            d[i][j] = INF;
        }
    }

    //スタート地点をキューに入れ、その点の距離を0にする
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    // キューが空になるまでループ
    while (que.size()){
        //キューの先頭を取り出す
        P p = que.front();
        que.pop();
        if (p.first == gx && p.second == gy) break;

        for (int i=0;i<4;i++){
            //移動した後の点を(nx, ny) とする
            int nx = p.first + dx[i], ny = p.second + dy[i];

            //移動が可能かの判定とすでに訪れたことがあるかの判定(d[nx][ny] != INF なら訪れたことがある)
            if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF){
                // 移動できるならキューに入れ、その点の距離をpからの距離 + 1で確定する
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}



int main()
{
    std::cin >> N >> M;
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            std::cin >> maze[i][j];
            if (maze[i][j] == 'S'){
                sx = i;
                sy = j;
            }

            if (maze[i][j] == 'G'){
                gx = i;
                gy = j;
            }
        }
    }

    //きちんと入力できているか確認
    // for (int i=0;i<N;i++){
    //     for (int j=0;j<M;j++){
    //         std::cout << maze[i][j];
    //     }
    //     printf("\n");
    // }

    int ans = bfs();
    printf("%d\n", ans);


}
