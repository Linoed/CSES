#include <bits/stdc++.h>


using namespace std;

pair<pair<int, int>, int> v[200010];
int lowest[200010];
int highest[200010];


int main(void) {

    int n;
    cin >> n;

    int a, b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        v[i] = {{a, b}, i};
    }

    sort(v, v + n, [&](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
        if (a.first.first != b.first.first) return a.first.first < b.first.first;
        if (a.first.second != b.first.second) return a.first.second > b.first.second;
        return a.second < b.second;
    });

    // for each item, want to check if any items to the right have lower rhs
    lowest[n - 1] = v[n - 1].first.second;
    for (int i = n - 2; i >= 0; --i) {
        lowest[i] = min(lowest[i + 1], v[i].first.second);
    }
    highest[0] = v[0].first.second;
    for (int i = 1; i < n; ++i) {
        highest[i] = max(highest[i - 1], v[i].first.second);
    }

    vector<int> res1(n);
    for (int i = 0; i < n - 1; ++i) {
        if (lowest[i + 1] <= v[i].first.second) {
            res1[v[i].second] = 1;
        }
        else res1[v[i].second] = 0;
    }

    vector<int> res2(n);
    for (int i = 1; i < n; ++i) {
        if (highest[i - 1] >= v[i].first.second) {
            res2[v[i].second] = 1;
        }
        else res2[v[i].second] = 0;
    }

    for (auto x : res1) cout << x << " ";
    cout << "\n";
    for (auto x : res2) cout << x << " ";
    cout << "\n";


}