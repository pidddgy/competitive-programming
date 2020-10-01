// https://codeforces.com/contest/271/problem/D

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

const int MAXN = 2000;
const int SEED = 131;
const int SEED2 = 696969697;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    int k;

    cin >> s >> t >> k;
    int n = sz(s);
    s = "."+s;

    set<pii> S;
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        int bad = 0;
        int val1 = 0, val2 = 0;
        int e1 = SEED, e2 = SEED2;
        for(int j = i; j <= n; j++) {
            if(t[s[j]-'a'] == '0') bad++;
            
            val1 += s[j] * e1;
            val2 += s[j] * e2;

            e1 *= SEED;
            e2 *= SEED2;

            if(bad <= k) {
                S.emplace(pii(val1, val2)); 
            }
        }
    }

    cout << sz(S) << endl;
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