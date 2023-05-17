#define MOD 1000000007
#include <bits/stdc++.h>


using namespace std;


int modadd(long long a, long long b) {
    return ((a + b) % MOD + MOD) % MOD;
}

long long a[1000010];
long long b[1000010];

int main(void) {

    int t;
    cin >> t;

    int n;

    a[1] = 1;
    b[1] = 1;

    for (int i = 2; i <= 1000000; ++i) {
        a[i] = modadd(2 * a[i - 1], b[i - 1]);
        b[i] = modadd(4 * b[i - 1], a[i - 1]);
    }

    while (t--) {
        cin >> n;
        cout << modadd(a[n], b[n]) << '\n';
    }
}

// towers with the same block at the top row = a
// towers with different block at the top row = b


// a can either fuse a 2x1 block onto every a, or add a 2x1 block onto every a and b
// thus a(n) = 2 * a(n - 1) + b(n - 1)

// b can either put two 1x1 blocks ontop of every a and b
// or fuse only left, fuse only right, fuse both 1x1 blocks onto every b
// thus b(n) = 4 * b(n - 1) + a(n - 1)