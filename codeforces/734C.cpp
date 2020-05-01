// https://codeforces.com/contest/734/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
const int maxmk = 200500;

int a[maxmk], b[maxmk], c[maxmk], d[maxmk];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int x, s;
    cin >> x >> s;

    for(int i = 1; i <= m; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    for(int i = 1; i <= k; i++) {
        cin >> c[i];
    }

    for(int i = 1; i <= k; i++) {
        cin >> d[i];
    }

    a[0] = x;
    b[0] = 0;

    c[0] = 0;
    d[0] = 0;

    int ans = LLONG_MAX;
    for(int i = 0; i <= m; i++) {
        if(b[i] > s) continue;
        int l = 0;
        int r = k;
        int lastgood = -1;
        while(l <= r) {
            int mid = (l+r)/2;

            if(d[mid] <= s-b[i]) {
                l = mid+1;
                lastgood = mid;
            } else {
                r = mid-1;
            }
        }

        int cost = ((n-c[lastgood]) * a[i]);

        // watch(i)
        // watch(cost)
        // watch(lastgood)

        ans = min(ans, cost);
    }

    cout << ans << endl;
}