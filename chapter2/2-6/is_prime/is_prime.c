#include <stdio.h>
#include <stdbool.h>


//素数判定
bool is_prime(int n){
    for (int i = 2;i*i <= n;i++){
        if (n % i == 0){
            return false;
        }
    }
    return n =! 1;
}



int main(){
    int n;
    scanf("%d", &n);

    if (is_prime(n)){
        printf("Yes\n");
    }else{
        printf("No\n");
    }

    return 0;
}
