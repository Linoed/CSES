#include <bits/stdc++.h>


using namespace std;




int main(void) {

    int n;
    cin >> n;

    stack<pair<int, int>> s;
    int x;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        while (!s.empty() && s.top().first >= x) {
            s.pop();
        }
        if (s.empty()) cout << "0 ";
        else cout << s.top().second << ' ';
        s.push({x, i});
    }
    cout << '\n';

}