// https://codeforces.com/contest/1395/problem/C

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

const int maxn = 250;
int n, m;
int a[maxn], b[maxn];
int dp[maxn][1 << 10];
set<int> allc[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    
    // each i will have at most m possibel masks
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            allc[i].emplace(a[i]&b[j]);
        }
    }

    dp[0][0] = true;

    // "push up" dp
    for(int i = 0; i <= n; i++) {
        for(int mask = 0; mask <= (1 << 9)-1; mask++) {
            if(!dp[i][mask]) continue;
            for(int c: allc[i+1]) {
                cerr << "pushing from " << i << " " << bitset<8>(mask) << " to " << i+1 << " " << bitset<8>(mask|c) << " using " << c << endl;
                dp[i+1][mask|c] = true;
            }
        }
    }
    
    for(int mask = 0; mask <= (1 << 9)-1; mask++) {
        if(dp[n][mask]) {
            cout << mask << endl;
            return 0;
        }
    }

    assert(false);
}

/*
use dp

dp[i][mask] = on the ith move, can we get to some bitmask?

find the smallest mask possible

time complexity = n*512*m

20 480 000
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
