// https://codeforces.com/contest/404/problem/C

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 100500;

pii d[maxn];
vector<int> v[maxn];
int deg[maxn];

void no() {
    cout << -1 << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> d[i].fi;
        d[i].se = i;
    }

    sort(d+1, d+n+1);
    if(d[1].fi != 0) no();

    v[0].emplace_back(d[1].se);
    
    vector<pii> ans;

    for(int i = 2; i <= n; i++) {
        if(d[i].fi == 0 or v[d[i].fi-1].empty()) {
            cerr << "failed on " << i << endl;
            no();
        }

        deg[v[d[i].fi-1].back()]++;
        deg[d[i].se]++;
        ans.emplace_back(v[d[i].fi-1].back(), d[i].se);

        if(deg[v[d[i].fi-1].back()] == k) {
            v[d[i].fi-1].pop_back();
        }
        if(k > 1) {
            v[d[i].fi].emplace_back(d[i].se);
        }
    }

    cout << sz(ans) << endl;
    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}

/*

distance with d builds off d-1

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
