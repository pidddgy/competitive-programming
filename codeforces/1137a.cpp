// https://codeforces.com/contest/1137/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int a[n+1][m+1];
    vector<int> row[n+1];
    vector<int> col[m+1];

    set<int> rowS[n+1];
    set<int> colS[m+1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            rowS[i].emplace(a[i][j]);
            colS[j].emplace(a[i][j]);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int x: rowS[i]) {
            row[i].emplace_back(x);
        }
    }
    for(int i = 1; i <= m; i++) {
        for(int x: colS[i]) {
            col[i].emplace_back(x);
        }
    }

    // for(int i = 1; i <= n; i++) {
    //     for(int x: row[i]) {
    //         cerr << x << " ";
    //     }
    //     cerr << endl;
    // }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            // calculate using row pos
            int rowpos = -1;
            int l = 0;
            int r = row[i].size()-1;
            while(l <= r) {
                int m = (l+r)/2;
                if(row[i][m] < a[i][j]) {
                    rowpos = m;
                    l = m+1;
                } else {
                    r = m-1;
                }
            }

            int colpos = -1;
            l = 0;
            r = col[j].size()-1;
            while(l <= r) {
                int m = (l+r)/2;
                if(col[j][m] < a[i][j]) {
                    colpos = m;
                    l = m+1;
                } else {
                    r = m-1;
                }
            }

            rowpos++;
            colpos++;

            cout << max(rowpos, colpos) + max(row[i].size()-rowpos, col[j].size()-colpos) << " ";

            // cerr << rowpos << "," << colpos << "," << R << " ";
            
        }
        cout << endl;
    }

}