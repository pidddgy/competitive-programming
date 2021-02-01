// https://codeforces.com/contest/442/problem/B

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

const int maxn = 105;

ld calc(vector<ld> v) {
    ld ans = 0;

    for(int i = 0; i < sz(v); i++) {
        ld p = v[i];
        for(int j = 0; j < sz(v); j++) {
            if(i == j) continue;

            p *= (1.0-v[j]);
        }
        ans += p;
    }

    return ans;
}

ld a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);

    vector<ld> cur;

    for(int i = 1; i <= n; i++) {
        vector<ld> b = cur;

        b.emplace_back(a[i]);

        if(calc(b) > calc(cur)) {
            cur = b;
        }
    }

    cout << calc(cur) << endl;
}

/*

if we have a set

ans = 0
for i in set
    ans += p(x) * 1-p(all others)

guess: loop from greatest to least and check if adding improves the answer



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
