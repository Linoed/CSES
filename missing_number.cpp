#include <bits/stdc++.h>

using namespace std;


bool arr[200010] = {0};

int main(void) {
    int n;
    cin >> n;

    int x;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x;
        arr[x] = true;
    }

    for (int i = 1; i <= n; ++i) if (!arr[i]) cout << i << "\n";
}