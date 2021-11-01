#include <stdio.h>
#include <stdbool.h>

typedef long long ll;

//素数判定
bool is_prime(ll n){
    for (ll i = 2;i*i <= n;i++){
        if (n % i == 0){
            return false;
        }
    }
    return n =! 1;
}

ll mod_pow(ll x, ll n, ll mod){
    ll res = 1;
    while (n > 0){
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }

    return res;
}

ll mod_pow_new(ll x, ll n, ll mod){
    if (n == 0) return 1;
    ll res = mod_pow(x * x % mod, n / 2, mod);
    if (n & 1) res = res * x % mod;
    return res;
}

int main(){
    ll n;
    scanf("%lld", &n);

    if (is_prime(n) || n < 2){
        printf("No");
        return 0;
    }else{
        for (ll i=2;i<n;i++){
            ll  mod_ans = mod_pow(i, n, n);
            if (mod_ans != i){
                printf("No");
                return 0;
            }
        }

        printf("Yes");
        return 0;
    }
}
