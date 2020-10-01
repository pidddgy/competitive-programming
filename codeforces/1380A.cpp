// https://m1.codeforces.com/contest/1380/problem/A

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
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

        vector<int> a(n+1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<pii> mi(n+1);
        vector<pii> ma(n+1);
        
        mi[1] = pii(a[1], 1);
        for(int i = 2; i <= n; i++) {
            mi[i] = mi[i-1];

            if(a[i] < mi[i].fi) {
                mi[i] = pii(a[i], i);
            }
        }

        ma[n] = pii(a[n], n);
        for(int i = n-1; i >= 1; i--) {
            ma[i] = ma[i+1];

            if(a[i] > ma[i].fi) {
                ma[i] = pii(a[i], i);
            }
        }

        string ans = "NO";
        int ind = -1;
        for(int i = 2; i <= n-1; i++) {
            if((mi[i-1].fi < a[i]) and (a[i] > ma[i+1].fi)) {
                ans = "YES";
                ind = i;
            }
        }

        if(ans == "YES") {
            cout << mi[ind-1].se << " " << ind << " " << ma[ind+1].se << endl;
        } else {
            cout << ans << endl;
        }
    }
}
