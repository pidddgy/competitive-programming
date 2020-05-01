5
4 7
7 4
2 11
9 7
1 1
// https://codeforces.com/contest/1333/problem/B

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
        int n;
        cin >> n;

        bool have1[n+1];
        bool haveneg[n+1];

        for(int i = 0; i <= n; i++) {
            have1[i] = false;
            haveneg[i] = false;
        }

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(a[i] == 1) {
                have1[i] = true;
            }

            if(a[i] == -1) {
                haveneg[i] = true;
            }
        }

        for(int i = 2; i <= n; i++) {
            if(have1[i]) continue;
            have1[i] = have1[i-1];
        }

        for(int i = 2; i <= n; i++) {
            if(haveneg[i]) continue;
            haveneg[i] = haveneg[i-1];
        }

        // for(int i = 1; i <= n; i++) {
        //     cerr << haveneg[i] << " ";
        // }
        // cerr << endl;

        int b[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        string ans = "YES";
        for(int i = n; i >= 1; i--) {
            if(a[i] > b[i]) {
                if(!haveneg[i-1]) ans = "NO";
            } else if(a[i] < b[i]) {
                if(!have1[i-1]) ans = "NO";
            }
        }

        cout << ans << endl;
    }
}