// https://codeforces.com/contest/1249/problem/D2

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

const int maxn = 200500;

int n, k;

int d[maxn];

// e[i] all r with l == i
vector<pii> add[maxn];
vector<pii> rem[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;

        add[a].emplace_back(b, i);
        rem[b+1].emplace_back(b, i);
    }

    multiset<pii, greater<pii>> S;
    vector<int> ans;

    for(int i = 1; i <= 2e5; i++) {
        for(pii x: add[i]) {
            S.emplace(x);
        }

        for(pii x: rem[i]) {
            if(S.count(x))
                S.erase(S.lower_bound(x));
        }

        while(sz(S) > k) {
            ans.emplace_back((*S.begin()).se);
            S.erase(S.begin());
        }
    }

    cout << sz(ans) << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
