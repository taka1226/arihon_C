#include <stdio.h>
#include <stdlib.h>

int extgcd(int a, int b, int* x, int* y){
    int d = a;
    if (b != 0){
        d = extgcd(b, a % b, y, x);
        *y -= (a / b) * *x;
    }else{
        *x = 1;
        *y = 0;
    }
    return d;
}


int main(){
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    int x, y;
    int d = extgcd(a,b , &x, &y);
    if (d != 1){
        printf("-1");
    }else{
        printf("x: %d, ", x);
        printf("y: %d\n", y);
    }
}
