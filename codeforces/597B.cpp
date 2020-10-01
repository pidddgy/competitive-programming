// https://codeforces.com/contest/597/problem/B

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 500500;

pii a[maxn];
int dp[maxn];

bool comp(pii &l, pii &r) {
    if(l.se != r.se) {
        return l.se < r.se;
    }

    return l.fi < r.fi;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    sort(a+1, a+n+1, comp);

    for(int i = 1; i <= n; i++) {
        int l = 0;
        int r = i-1;
        int lok = -1;

        while(l <= r) {
            int m = (l+r)/2;

            if(a[m].se < a[i].fi) {
                l = m+1;
                lok = m;
            } else {
                r = m-1;
            }
        }

        dp[i] = max(dp[i-1], dp[lok]+1);
    }


    cout << dp[n] << endl;
}
