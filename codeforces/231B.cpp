// https://codeforces.com/contest/231/problem/B

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

const int shift = (int)1e4+3;
const int maxn = 105;

pii par[maxn][2e4+500];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d, l;
    cin >> n >> d >> l;

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < (int)2e4+500; j++) {
            par[i][j] = -1;
        }
    }

    for(int i = 1; i <= l; i++) {
        par[n][i] = pii(n, i);
    }

    for(int i = n-1; i >= 1; i--) {
        for(int j = -1e4; j <= 1e4; j++) {
            
        }
    }    
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
