#include <bits/stdc++.h>

using namespace std;


int main(void) {
    long long x;
    cin >> x;

    while (x > 1) {
        cout << x << " ";
        if (x & 1) x = 3 * x + 1;
        else x /= 2;
    }
    cout << x << "\n";
}