// https://codeforces.com/contest/1334/problem/0

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
        int n;
        cin >> n;

        string ans = "YES";
        pii a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i].fi >> a[i].se;
        }

        if(a[1].se > a[1].fi) {
            ans = "NO";
        }
        // plays or clears decrease or clears increase and plays dont increase same
        for(int i = 2; i <= n; i++) {
            // cerr << "on " << i << endl;
            // watch()
            if((a[i].fi < a[i-1].fi) or (a[i].se < a[i-1].se)) {
                ans = "NO";
            } else if((a[i].se - a[i-1].se) > (a[i].fi - a[i-1].fi)) {
                ans = "NO";
            }
        } 

        cout << ans << endl;
    }
}