// https://codeforces.com/contest/617/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

int cost(int x1, int y1, int x2, int y2) {
    if(x1 == x2 or y1 == y2) {
        return 1;
    } else {
        return 2;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x[4], y[4];

    for(int i = 1; i <= 3; i++) {
        cin >> x[i] >> y[i];
    }

    if(x[1] == x[2] and x[2] == x[3]) {
        cout << 1 << endl;
        return 0;
    }

    if(y[1] == y[2] and y[2] == y[3]) {
        cout << 1 << endl;
        return 0;
    }

    int ans = 3;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            for(int k = 1; k <= 3; k++) {
                if(set<int>({i, j, k}).size() != 3) continue;

                if(x[i] == x[j]) {
                    int a = min(y[i], y[j]);
                    int b = max(y[i], y[j]);

                    if(!(a < y[k] and y[k] < b)) {
                        ans = 2;
                    }
                }      

                if(y[i] == y[j]) {
                    int a = min(x[i], x[j]);
                    int b = max(x[i], x[j]);

                    if(!(a < x[k] and x[k] < b)) {
                        ans = 2;
                    }
                }                
            }
        }
    }

    cout << ans << endl;
}