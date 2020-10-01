// https://codeforces.com/contest/1184/problem/C1

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, map<int, int>> point;

    vector<pii> all;
    for(int i = 1; i <= 4*n+1; i++) {
        int x, y;
        cin >> x >> y;

        all.emplace_back(x, y);
        point[x][y] = true;
    }

    for(int i = 0; i <= 50; i++) {
        for(int j = 0; j <= 50; j++) {
            // i, j == start;
            for(int sz = 1; sz <= 50; sz++) {
                int cx = i+sz;
                int cy = j+sz;

                set<pii> S;

                for(int k = i; k <= cx; k++) {
                    if(point[k][j]) {
                        S.emplace(k, j);
                    }
                }

                for(int k = j; k <= cy; k++) {
                    if(point[i][k]) {
                        S.emplace(i, k);
                    }
                }
                
                for(int k = cx; k >= i; k--) {
                    if(point[k][cy]) {
                        S.emplace(k, cy);
                    }
                }

                for(int k = cy; k >= j; k--) {
                    if(point[cx][k]) {
                        S.emplace(cx, k);
                    }
                }

                if(S.size() == 4*n) {
                    for(pii x: all) {
                        if(!S.count(x)) {
                            cout << x.fi << " " << x.se << endl;
                            return 0;
                        }
                    }
                }
               


            }
        }
    }
}