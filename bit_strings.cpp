#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007


int mod(long long x) {
    return ((x % MOD) + MOD) % MOD;
}


int modpow(long long n) {
    if (n == 0) return 1;
    if (n == 1) return 2;

    long long halfPow = modpow(n / 2);
    if (n & 1) return mod(mod(halfPow * halfPow) * 2);
    return mod(halfPow * halfPow);
}

int main(void) {
    int n;
    cin >> n;

    cout << modpow(n) << "\n";
}
