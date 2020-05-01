// https://codeforces.com/contest/1041/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 200500;

pii x[maxn];
int cost[maxn];
int psa[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    cin >> n >> h;

    for(int i = 1; i <= n; i++) {
        cin >> x[i].fi >> x[i].se;
    }
    
    for(int i = 2; i <= n; i++) {
        cost[i] = x[i].fi-x[i-1].se;
    }

    for(int i = 1; i <= n; i++) {
        psa[i] = cost[i] + psa[i-1];
    }

    // for(int i = 1; i <= n; i++) {
    //     cerr << psa[i] << " ";
    // }
    // cerr << endl;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int l = i;
        int r = n;
        int lastgood = -1;
        while(l <= r) {
            int m = (l+r)/2;

            if(psa[m]-psa[i] < h) {
                lastgood = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }

        int c = psa[lastgood]-psa[i];
        // watch(i)
        // watch(x[i].fi)
        // watch(lastgood)
        // watch(c)
        // cerr << "can go from " << x[i].fi << " to " << x[lastgood].se+(h-c) << endl;
        // cerr << endl;
        ans = max(ans, (x[lastgood].se+(h-c)) - x[i].fi);
    }

    cout << ans << endl;
}

/*


5 10
3 4
10 11
12 13
14 16
18 20


*/