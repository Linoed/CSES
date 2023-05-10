#include <bits/stdc++.h>

using namespace std;


int p[21];

int main(void) {
    int n;
    cin >> n;

    long long best = 1LL << 62;

    for (int i = 0; i < n; ++i) cin >> p[i];



    for (int i = 0; i < (1 << n); ++i) {
        long long w1 = 0;
        long long w2 = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) w1 += p[j];
            else w2 += p[j];
        }


        best = min(best, abs(w2 - w1));
    }
    cout << best << "\n";
}