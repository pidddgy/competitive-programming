// https://codeforces.com/contest/489/problem/D

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

const int maxn = 3005;

int trng(int number) {
    return (number*(number+1))/2;
}

set<int> G[maxn];
int ways[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace(v);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        watch(i)
        for(int j = 1; j <= n; j++) {
            ways[j] = 0;
        }

        for(int adj: G[i]) {
            watch(adj)
            for(int adj2: G[adj]) {
                if(i == adj2) continue;
                watch(adj2)

                ways[adj2]++;
            }
        }

        for(int j = 1; j <= n; j++) {
            cerr << j << " " << ways[j] << endl; 
            ans += (ways[j]*(ways[j]-1))/2;
        }
    }

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
