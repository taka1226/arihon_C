#include <stdio.h>
#include <stdlib.h>

int my_gcd(int a, int b){
    if (b == 0){
        return a;
    }
    return my_gcd(b, a % b);
}

int test_func(int a, int b, int* x, int* y){
    *x += 3;
    *y += 4;
    return a;
}
int main(){
    int x = 1;
    int y = 4;
    int c = test_func(1, 3, &x, &y);

    return 0;
}
