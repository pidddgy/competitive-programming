// https://codeforces.com/contest/272/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second

ll fac[(int)1e6];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    map<int, set<int>> unique;
    map<int, int> all;
    map<int, int> dup;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(unique[x].count(i)) dup[x] += 2;
        unique[x].emplace(i);
        all[x]++;
    }    

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(unique[x].count(i)) dup[x] += 2;
        unique[x].emplace(i);
        all[x]++;
    }

    int m;
    cin >> m;

    ll ans = 1LL;

    fac[1] = 1LL;

    for(int i = 2; i <= 2e5; i++) {
        fac[i] = (i*fac[i-1])%m;
    }

    for(auto x: all) {
        int mult = 1;
        cerr << "on " << x.fi << endl;
        watch(x.se)
        int d = dup[x.fi];
        watch(d)
        for(int i = all[x.fi]; i >= d+1; i--) {
            cerr << "multing by " << i << endl;
            mult *= i;
            mult %= m;
        }

        watch(mult)
        ans *= mult;
        ans %= m;
        cerr << endl;
    }

    cout << ans << endl;
}
