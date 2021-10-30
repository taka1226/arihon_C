#include <stdio.h>
#include <stdlib.h>

int my_gcd(int a, int b){
    if (b == 0){
        return a;
    }
    return my_gcd(b, a % b);
}
int main(){
    // input 1 11 5 3
    // output 3
    int x1, y1, x2, y2;
    scanf("%d", &x1);
    scanf("%d", &y1);
    scanf("%d", &x2);
    scanf("%d", &y2);

    int dis_x = abs(x1-x2);
    int dis_y = abs(y1-y2);

    int ans;
    if (dis_x == 0 && dis_y == 0){
        ans = 0;
    }else{
        ans = my_gcd(dis_x, dis_y) - 1;
    }

    printf("%d\n", ans);

    return 0;
}
