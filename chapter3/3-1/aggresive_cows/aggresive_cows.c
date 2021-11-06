#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_N 100001
#define INF 1000000000

int N, M; //Mは牛の数
int x[MAX_N];

// 距離kで牛が置けるか
bool possible(int k){
    int last = 0;
    int now_location = 0;
    for (int i=1;i<M;i++){
        while(x[now_location] - x[last] < k){
            now_location++;

            if (now_location == N) return false;
        }
        last = now_location;
    }

    return true;

}

//	並べ替え基準を示す関数(昇順)
int cmpnum(const void * n1, const void * n2)
{
	if (*(int *)n1 > *(int *)n2)
	{
		return 1;
	}
	else if (*(int *)n1 < *(int *)n2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}


int main(){
    scanf("%d %d", &N, &M);
    for (int i=0;i<N;i++){
        scanf("%d", &x[i]);
    }

    //x[i] をソート
    qsort(x, N, sizeof(int), cmpnum);

    //2分探索
    int lb = 0;
    int rb = INF;
    while (rb - lb > 1){
        int mid = (lb + rb) / 2;

        if (possible(mid)){
            lb = mid;
        }else{
            rb = mid;
        }
    }

    printf("%d\n", lb);



    return 0;
}
