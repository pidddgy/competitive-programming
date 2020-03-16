// http://codeforces.com/contest/1207/problem/B

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second

using namespace std;
int a[60][60];
int b[60][60];
vector<pii> ans;
int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for(int i = 1; i <= n-1; i++) {
        for(int j = 1; j <= m-1; j++) {
            if(a[i][j] and a[i][j+1] and a[i+1][j] and a[i+1][j+1]) {
                b[i][j] = 1;
                b[i+1][j] = 1;
                b[i][j+1] = 1;
                b[i+1][j+1] = 1;

                ans.emplace_back(i, j);
            }
        } 
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] != b[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << ans.size() << endl;
    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}
