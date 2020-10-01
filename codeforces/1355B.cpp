// https://codeforces.com/contest/1355/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
// #define cerr if(false) cerr

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        sort(a+1, a+n+1);

        int ans = 0;
        int unused = 0;
        for(int i = 1; i <= n; i++) {
            int need = a[i];

            if(unused >= need-1) {
                ans++;
                unused = 0;
            } else {
                unused++;
            }
        }

        cout << ans << endl;
    }
}

/*
1
7
1 1 2 4 5 7 8
*/