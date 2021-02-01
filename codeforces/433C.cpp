// https://codeforces.com/contest/433/problem/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
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

int a[maxn];
vector<int> v[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int tot = 0;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        if(i >= 2) tot += abs(a[i]-a[i-1]);
    }

    for(int i = 1; i <= m; i++) {
        if((i-1 >= 1) and (a[i-1] != a[i])) {
            v[a[i]].emplace_back(a[i-1]);
        }

        if((i+1 <= m) and (a[i+1] != a[i])) {
            v[a[i]].emplace_back(a[i+1]);
        }
    }

    int ma = 0;
    for(int i = 1; i <= n; i++) {
        watch(i)
        sort(all(v[i]));

        int orig = 0;
        for(int x: v[i]) {
            orig += abs(x-i);
        }

        vector<int> pre(sz(v[i]), 0);
        vector<int> suf(sz(v[i]), 0);

        int cum = 0;
        for(int j = 0; j < sz(v[i]); j++) {
            cum += v[i][j];
            pre[j] = cum;
        }

        cum = 0;
        for(int j = sz(v[i])-1; j >= 0; j--) {
            cum += v[i][j];
            suf[j] = cum;
        }

        int ne = LLONG_MAX;
        for(int j = 0; j < sz(v[i]); j++) {
            watch(j)
            int cost = 0;

            if(j > 0) {
                watch((v[i][j]*(j)) - pre[j-1])
                cost += (v[i][j]*(j)) - pre[j-1];
            }
            
            if(j+1 < sz(v[i])) {
                watch(suf[j+1] - v[i][j]*(sz(v[i])-j-1))
                cost += suf[j+1] - v[i][j]*(sz(v[i])-j-1);
            }

            
            watch(cost)

            ne = min(ne, cost);
        }

        watch(ne)
        for(int x: v[i]) {
            cerr << x << " ";
        }
        cerr << endl;

        ma = max(ma, orig-ne);
        cerr << endl;
    }

    cout << tot-ma << endl;
}

/*

get total

ma = 0
for i in 1..n
    get all values that are connected to an i that aren't i

    ma = max(ma, orig-new)

total-ma




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
