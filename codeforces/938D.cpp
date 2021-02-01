// https://codeforces.com/contest/938/problem/D

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

int n, m;

// .fi = weight, .se = destination
vector<pii> G[maxn];
int ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= m; i++) { 
        int u, v, w;
        cin >> u >> v >> w;
        
        G[u].emplace_back(w, v);
        G[v].emplace_back(w, u);
    }

    // everything is negative because pq bad
    priority_queue<pii> pq;
    for(int i = 1; i <= n; i++) {
        cin >> ans[i];
        pq.push(pii(-ans[i], i));
    }

    while(!pq.empty()) {
        int d = -pq.top().fi;
        int S = pq.top().se;
        pq.pop();

        // already found better answer
        if(ans[S] < d) continue; 

        for(pii e: G[S]) {
            int nw = 2*e.fi + ans[S];
            if(nw < ans[e.se]) {
                ans[e.se] = nw;
                pq.push(pii(-nw, e.se));
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

multiply each edge by 2
each node can go to itself

a -> b -> c
ans[u] = min(ans[u], 2*edge.w + ans[v])

it is never optimal for any i to go to a j if a[j] >= a[i] or any edge weight >= a[i]

for all i in sorted(a[i])
    add all edges with weight < a[i]

    do dijkstra




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
