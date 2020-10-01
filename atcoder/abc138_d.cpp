// https://atcoder.jp/contests/abc138/tasks/abc138_d

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

vector<int> G[maxn];
bool vis[maxn];
int sum[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;

    for(int i = 1; i <= N-1; i++) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    while(Q--) {
        int p, x;
        cin >> p >> x;

        sum[p] += x;
    }

    queue<int> Qu;
    Qu.push(1);
    vis[1] = true;

    while(!Qu.empty()) {
        int S = Qu.front(); Qu.pop();

        for(int adj: G[S]) {
            if(!vis[adj]) {
                Qu.push(adj);
                vis[adj] = true;
                
                sum[adj] += sum[S];
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        cout << sum[i] << " ";
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
