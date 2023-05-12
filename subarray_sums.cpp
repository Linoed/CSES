// works for both Subarray Sums I and Subarray Sums II
#include <bits/stdc++.h>


using namespace std;


int main(void) {

    int n, x;
    cin >> n >> x;

    map<long long, int> mp;
    // mp.reserve(1 << 19);
    mp[0] = 1;

    long long sum = 0;
    long long res = 0;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        sum += a;
        res += mp[sum - x];
        mp[sum]++;
    }
    cout << res << '\n';

}