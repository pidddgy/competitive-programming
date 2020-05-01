// https://codeforces.com/contest/384/problem/B

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    // if k == 1 i > j
    // if k == 0 i < j
    int n, m, k;
    cin >> n >> m >> k;

    cout << (m*(m-1))/2 << endl;

    for(int i = 1; i <= m; i++) {
        for(int j = i+1; j <= m; j++) {
            if(k == 1) {
                cout << max(i, j) << " " << min(i, j) << endl;
            } else {
                cout << min(i, j) << " " << max(i, j) << endl;
            }
        }
    }
}