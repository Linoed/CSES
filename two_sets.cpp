#include <bits/stdc++.h>

using namespace std;


int main(void) {
    int n;
    cin >> n;

    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO\n";
        return 0;
    }

    vector<int> v1;
    vector<int> v2;


    if (n % 4 == 3) {
        v1 = {1, 2};
        v2 = {3};
        for (int i = 4; i <= n; i += 4) {
            v1.push_back(i);
            v1.push_back(i + 3);
            v2.push_back(i + 1);
            v2.push_back(i + 2);
        }
    }
    else {
        v1 = {1, 4};
        v2 = {2, 3};
        for (int i = 5; i <= n; i += 4) {
            v1.push_back(i);
            v1.push_back(i + 3);
            v2.push_back(i + 1);
            v2.push_back(i + 2);
        }
    }


    
    cout << "YES\n";
    cout << v1.size() << "\n";
    for (auto x : v1) cout << x << " ";
    cout << "\n";
    cout << v2.size() << "\n";
    for (auto x : v2) cout << x << " ";
    cout << "\n";
}