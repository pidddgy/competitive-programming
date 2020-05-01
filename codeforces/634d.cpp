// https://codeforces.com/contest/1335/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string a[10];
        for(int i = 1; i <= 9; i++) {
            string row;
            cin >> row;

            row = "."+row;

            a[i] = row;
        }

        // for(int i = 1; i <= 9; i++) {
        //     for(int j = 1; j <= 9; j++) {
        //         cerr << a[i][j];
        //     }
        //     cerr << endl;
        // }

        multiset<char> block[10];

        vector<pii> bounds = {pii(1, 3), pii(4, 6), pii(7, 10)};

        int cur = 1;
        for(pii x: bounds) {
            for(pii y: bounds) {
                for(int i = x.fi; i <= x.se; i++) {
                    for(int j = y.fi; j <= y.se; j++) {
                        block[cur].emplace(a[i][j]);
                    }
                }
                cur++;
            }
        }

        vector<pii> squares = {pii(1, 1), pii(2, 4), pii(3, 7),
        pii(4, 2), pii(5, 5), pii(6, 8),
        pii(7, 3), pii(8, 6), pii(9, 9)};

        int curBlock = 1;
        for(pii check: squares) {
            for(int thing = 1; thing <= 9; thing++) {
                char x = thing+'0';
                bool inRow = false;
                bool inCol = false;
                bool inBlock = false;

                for(int j = 1; j <= 9; j++) {
                    if(a[check.fi][j] == x and j != check.fi) inRow = true;
                }

                for(int j = 1; j <= 9; j++) {
                    if(a[j][check.se] == x and j != check.se) inCol = true;
                }

                if(a[check.fi][check.se] == x) {
                    if(block[curBlock].count(x) >= 2) {
                        inBlock = true;
                    }
                } else {
                    if(block[curBlock].count(x) >= 1) {
                        inBlock = true;
                    }
                }

                if(inRow and inCol and inBlock) {
                    block[curBlock].erase(block[curBlock].lower_bound(a[check.fi][check.se]));
                    // cerr << "setting " << check.fi << " " << check.se << " to " << x << endl;
                    a[check.fi][check.se] = x;
                    block[curBlock].emplace(x);
                    break;
                }
            }
            curBlock++;
        }

        for(int i = 1; i <= 9; i++) {
            for(int j = 1; j <= 9; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
        
    }
}

/*

1
534678912
672195348
198342567
859761423
426853791
713924856
961537284
287419635
345286179

*/