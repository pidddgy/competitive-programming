// https://codeforces.com/contest/1148/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define int long long
int n, m, ta, tb, k;

const int maxn = 200500;

int a[maxn], b[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> ta >> tb >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    if(k >= n) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    for(int i = 0; i <= k; i++) {
        if(i > n) break;

        int rem = k-i;

        int lb = a[i+1]+ta;

        int l = 1;
        int r = m;
        int lok = -1;
        while(l <= r) {
            int md = (l+r)/2;

            if(b[md] >= lb) {
                lok = md;
                r = md-1;
            } else {
                l = md+1;
            }
        }

        if(lok == -1) {
            ans = INT_MAX;
        }
        watch(i)
        watch(lok)
        watch(lb)
        watch(rem)
        if(lok+rem > m) {
            ans = INT_MAX;
        } else {
            cerr << "maxing with " << b[lok+rem]+tb << endl;
            ans = max(ans, b[lok+rem]+tb);
        }
        cerr << endl;
    }

    if(ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}