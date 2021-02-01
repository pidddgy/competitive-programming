// https://codeforces.com/contest/452/problem/B

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
int n, m;
bool in(int x, int y) {
    if(0 <= x and x <= n) {
        if(0 <= y and y <= m) {
            return true;
        }
    }

    return false;
}

int sq(int n) {
    return n*n;
}

ld dis(pii a, pii b) {
    return sqrt(sq(abs(a.fi-b.fi)) + sq(abs(a.se-b.se)));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    set<pii> S; 

    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            if(in(i, j)) S.emplace(i, j);
            if(in(n-i, m-j)) S.emplace(n-i, m-j);
            if(in(i, m-j)) S.emplace(i, m-j);
            if(in(n-i, j)) S.emplace(n-i, j);

        }
    }

    vector<pii> v;
    for(pii x: S) {
        cerr << x.fi << " " << x.se << endl;
        v.emplace_back(x);
    }

    vector<int> ans;
    ld ma = 0;
    for(int i = 0; i < sz(v); i++) {
        for(int j = 0; j < sz(v); j++) {
            for(int k = 0; k < sz(v); k++) {
                for(int l = 0; l < sz(v); l++) {
                    if(sz(set<int>({i, j, k, l,})) != 4) continue;
                    
                    ld loc = 0;
                    loc += dis(v[i], v[j]);
                    loc += dis(v[j], v[k]);
                    loc += dis(v[k], v[l]);

                    if(loc > ma) {
                        ma = loc;
                        ans = {i, j, k, l};
                    }
                }
            }
        }
    }

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);
    watch(ma)
    for(int x: ans) {
        cout << v[x].fi << " " << v[x].se << endl;
    }
}

/*

pick points around the big diagonal

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
