#include <bits/stdc++.h>

using namespace std;

int x[200010];

int main(void) {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) cin >> x[i];

    sort(x, x + n);

    long long lowest = 1;
    for (int i = 0; i < n; ++i) {
        if (lowest < x[i]) {
            cout << lowest << "\n";
            return 0;
        }
        lowest += x[i];
    }
    cout << lowest << "\n";
}


// if we have x[i] and lowest

// x[i] can add to all the numbers 0 up to lowest - 1
// if lowest < x[i], cant add without a gap

