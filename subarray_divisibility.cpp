#include <bits/stdc++.h>

using namespace std;


int n;

int modadd(int a, int b) {
    return ((a + b) % n + n) % n;
}

int main(void) {

    cin >> n;

    map<int, long long> mp;
    mp[0] = 1;

    int a;
    int sum = 0;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        sum = modadd(sum, a);
        res += mp[sum];
        mp[sum]++;
    }   
    cout << res << '\n';



}