#include <bits/stdc++.h>

using namespace std;


int color[100010] = {0};

int main(void) {
    int pts = 0;

    vector<int> res(n);
    int pts = 0;
    for (int idx = 0; idx < n; ++i) {
        int i = queries[idx][0];
        int c = queries[idx][1];

        if (color[i] != 0) {
            if (i - 1 >= 0 && color[i - 1] == color[i]) --pts;
            if (i + 1 < n && color[i + 1] == color[i]) --pts;
        }
        

        if (i - 1 >= 0 && color[i - 1] == c) ++pts;
        if (i + 1 < n && color[i + 1] == c) ++pts;

        color[i] = c;
        res[idx] = pts;
    }
    return res;
}