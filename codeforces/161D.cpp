// https://codeforces.com/contest/161/problem/D

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

const int maxn = 50000;
const int maxk = 500;


int n, k;
vector<int> G[maxn+50];
int ans = 0;

// Stores number of nodes current node has depth away
int dp[maxn+50][maxk+50];

void dfs(int n, int par) {
    dp[n][0]++;
    
    for(int adj: G[n]) {
        if(adj == par) continue;

        dfs(adj, n);

        for(int i = 0; i <= k-1; i++) {
            ans += dp[adj][i] * dp[n][k-i-1];
        }   

        for(int i = 0; i <= k-1; i++) {
            dp[n][i+1] += dp[adj][i];
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 1; i <= n-1; i++) {
        int a, b;
        cin >> a >> b;

        G[a].emplace_back(b);
        G[b].emplace_back(a);        
    }

    dfs(1, -1);

    cout << ans << endl;
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
