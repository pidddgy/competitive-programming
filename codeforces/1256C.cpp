// https://codeforces.com/contest/1256/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second

const int maxnm = 1005;

int c[maxnm], ans[maxnm];
pii a[maxnm];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, d;
    cin >> n >> m >> d;

    for(int i = 1; i <= m; i++) {
        cin >> c[i];
    }

    int ind = 1;
    for(int i = 1; i <= m; i++) {
        a[i].fi = ind;
        a[i].se = ind+c[i]-1;

        ind = ind+c[i];
    }

    a[0].fi = a[0].se = 0;
    a[m+1].fi = a[m+1].se = n+1;

    for(int it = 1; it <= 1000; it++) {
        for(int i = m; i >= 1; i--) {
            while(a[i-1].se+d > a[i].fi and a[i].se < a[i+1].fi-1) {
                a[i].fi++;
                a[i].se++;
            }
        }
    }

    if(a[m+1].fi-a[m].se > d) {
        cout << "NO" << endl;
        return 0;
    }

    for(int i = 1; i <= m; i++) {
        cerr << a[i].fi << "," << a[i].se << endl;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = a[i].fi; j <= a[i].se; j++) {
            ans[j] = i;
        }
    }

    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
