#include <bits/stdc++.h>


using namespace std;


int main(void) {
    int n;
    cin >> n;

    int x;
    long long res = -1e9;
    long long sum = -1e9;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (sum < 0) {
            sum = x;
        }
        else {
            sum += x;
        }
        res = max(res, sum);
    }

    cout << res << "\n";

}