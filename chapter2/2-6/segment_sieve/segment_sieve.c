#include <stdio.h>
#include <stdbool.h>

#define MAX_L 40
#define MAX_SQRT_B 40

typedef long long ll;
bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

void segment_sieve(ll a, ll b);
ll max(ll a, ll b);

// [a,b)の整数に対して篩を行う。is_prime[i - a] = true <=> iが素数
void segment_sieve(ll a, ll b){
    for (int i = 0;(ll)i * i < b; i++)is_prime_small[i] = true;
    for (int i = 0; i< b - a; i++) is_prime[i] = true;

    for (int i=2; (ll)i * i < b;i++){
        if (is_prime_small[i]){
            for (int j=2 * i;(ll)j * j < b;j+= i) is_prime_small[j] = false;
            for (ll j = max(2LL, (a + i - 1) / i) * i;j < b;j+=i) is_prime[j - a] = false;
            //for (ll j = max(2LL, (a / i + 1) * i); j < b;j+=i) is_prime[j - a] = false;
        }
    }
}

ll max(ll a, ll b){
    if (a > b) return a;
    else{
        return b;
    }
}

int main(){
    ll a = 12;
    ll b = 20;
    segment_sieve(a, b);
}
