// https://codeforces.com/contest/837/problem/B

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

    char a[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    string ans = "NO";

    if(n%3 == 0) {
        string S;

        for(int i = 0; i < 3; i++) {
            int frow = i*(n/3);
            char comp = a[frow][0];
            bool good = true;
            for(int j = 0; j < n/3; j++) {
                for(int k = 0; k < m; k++) {
                    if(a[frow+j][k] != comp) {
                        good = false;
                    }
                }
            }

            if(good) S += comp;
        }        

        sort(S.begin(), S.end());

        if(S == "BGR") {
            ans = "YES";
        }
    }
    
    if(m%3 == 0) {
        string S;

        for(int i = 0; i < 3; i++) {
            int fcol = i*(m/3);
            char comp = a[0][fcol];
            bool good = true;

            for(int j = 0; j < m/3; j++) {
                for(int k = 0; k < n; k++) {
                    if(a[k][fcol+j] != comp) {
                        good = false;
                    }
                }
            }

            if(good) S += comp;
        }

        sort(S.begin(), S.end());

        if(S == "BGR") {
            ans = "YES";
        }
    }

    cout << ans << endl;
}