// https://codeforces.com/contest/1365/problem/A

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 55;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        int row[n+1];
        int col[m+1];

        for(int i = 1; i <= n; i++) {
            row[i] = 1;
        }

        for(int i = 1; i <= m; i++) {
            col[i] = 1;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int x;
                cin >> x;

                if(x == 1) {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }

        int r = 0, c = 0;
        for(int i = 1; i <= n; i++) {
            r += row[i];
        }

        for(int i = 1; i <= m; i++) {
            c += col[i];
        }

        // watch(r)
        // watch(c)

        if(min(r, c)%2==1) {
            cout << "Ashish" << endl;
        } else {
            cout << "Vivek" << endl;
        }
    }
}
