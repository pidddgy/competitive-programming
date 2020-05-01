// https://codeforces.com/contest/1333/problem/0

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        char ans[n+1][m+1];
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(i % 2 == 1) {
                    if(j % 2 == 1) {
                        ans[i][j] = 'B';
                    } else {
                        ans[i][j] = 'W';
                    }
                } else {
                    if(j % 2 == 1) {
                        ans[i][j] = 'W';
                    } else {
                        ans[i][j] = 'B';
                    }
                }
            }
        }

        if((n % 2 == 0) or (m%2 == 0)) {
            bool found = false;
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    if(ans[i][j] == 'W') {
                        ans[i][j] = 'B';
                        found = true;
                        break;
                    }
                    if(found) break;
                }
                if(found) break;
            }
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
}