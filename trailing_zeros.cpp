#include <bits/stdc++.h>


using namespace std;


int main(void) {
    int n;
    cin >> n;

    int res = 0;
    for (int i = 5; i <= n; i *= 5) {
        res += n / i;
    }

    cout << res << "\n";



    // how many numbers div by 5, 25, 125 etc. here?
}