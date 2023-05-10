#include <bits/stdc++.h>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    cout << "0\n";
    if (n >= 2) cout << "6\n";
    if (n >= 3) cout << "28\n";
    for (int i = 4; i <= n; ++i) {
        // get how many outer spots there are
        // get how many 2nd inner spots there are
        // get the number of "other" spots
        
        long long res = 0;
        long long total = i * i;
        res += 4 * (total - 3);
        res += 8 * (total - 4);
        res += (4 + 4 * (i - 4)) * (total - 5);
        res += 4 * (i - 4) * (total - 7);
        res += (i - 4) * (i - 4) * (total - 9);
        cout << res / 2 << "\n";
    }
}

// chessboard can be split into regions
// let's say chessboard has n squares
// each corner piece can be paired with (n - 3) others
// each piece adjacent to corner paired with (n - 4) others
// each piece diagonal to corner paired with (n - 5) others
// other regions near edges can be paired with (n - 5) and (n - 7)
// center pieces can be paired with (n - 9)

// (n - 3): 4 pieces
// (n - 4): 8 pieces
// (n - 5): 4 + 4 * (n - 4) pieces
// (n - 7): 4 * (n - 4) pieces
// (n - 9): (n - 4) * (n - 4) pieces

// total result by 2 because we cant distinguish between different pairs