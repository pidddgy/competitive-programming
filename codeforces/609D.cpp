// https://codeforces.com/contest/609/problem/D

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

const int maxn = 200500;

int n, m, k, s;
pii a[maxn], b[maxn];

int t[maxn], c[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k >> s;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;

        if(i >= 2) a[i] = min(a[i], a[i-1]);
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i].fi;
        b[i].se = i;

        if(i >= 2) b[i] = min(b[i], b[i-1]);
    }

    for(int i = 1; i <= m; i++) {
        cin >> t[i] >> c[i];
    }

    int l = 1, r = n;
    int lgood = -1;
    while(l <= r) {
        int md = (l+r)/2;

        cerr << "trying " << md << endl;
        vector<int> costs;

        for(int i = 1; i <= m; i++) {
            if(t[i] == 1) {
                costs.emplace_back(a[md].fi*c[i]);
            } else {
                costs.emplace_back(b[md].fi*c[i]);
            }
        }

        sort(all(costs)); reverse(all(costs));

        int cur = 0, take = 0;
        watch(take)

        while(sz(costs) and costs.back()+cur <= s) {
            cur += costs.back();
            costs.pop_back();
            take++;
        }

        if(take >= k) {
            lgood = md;
            r = md-1;
        } else {
            l = md+1;
        }
    }

    cout << lgood << endl;
    if(lgood == -1) return 0;

    vector<pii> v;
    for(int i = 1; i <= m; i++) {
        if(t[i] == 1) {
            v.emplace_back(a[lgood].fi*c[i], i);
        } else {
            v.emplace_back(b[lgood].fi*c[i], i);
        }
    }

    sort(all(v));
    reverse(all(v));

    vector<pii> ans;
    for(int i = 1; i <= k; i++) {
        cout << v.back().se << " ";
        if(t[v.back().se] == 1) {
            cout << a[lgood].se;
        } else {
            cout << b[lgood].se;
        }
        cout << endl;

        v.pop_back();
    }
}

/*

given a coefficient and 2 arrays find the max number you can atke

binary search cancer

bsearch on day
    multiply all the gadgets by coefficients and push into vector
    construct psa of vector
    binary search

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
