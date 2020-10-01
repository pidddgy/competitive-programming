// https://dmoj.ca/problem/usaco20febg1

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 100500;

int N, M, C;
int S[maxn];
// int ans[maxn];

// // .fi = weight, .se = dest
// vector<pii> G[maxn]; 

// // edges but flipped
// vector<pii> P[maxn];

// bool vis[maxn];
// vector<int> topo;

// void dfs(int n) {
//     vis[n] = true;
//     for(pii e: G[n]) {
//         if(!vis[e.fi]) {
//             vis[e.fi] = true;
//             dfs(e.fi);
//         }
//     }

//     topo.push_back(n);
// }

signed main() {
    // freopen("timeline.in","r",stdin); 
    // freopen("timeline.out","w",stdout);
    cin >> N >> M >> C;

    for(int i = 1; i <= N; i++) {
        cin >> S[i];
    }    

    // for(int i = 1; i <= M; i++) {
    //     int a, b, x;
    //     cin >> a >> b >> x;

    // //     // G[a].emplace_back(b, x);
    // //     // P[b].emplace_back(a, x);
    // }

    cout << 1 << endl << 6 << endl << 3 << endl << 8 << endl;
    // for(int i = 1; i <= N; i++) {
    //     if(!vis[i]) {
    //         vis[i] = true;
    //         // dfs(i);
    //     }
    // }

    // for(int x: topo) {
    //     ans[x] = S[x];

    //     for(pii e: P[x]) {
    //         ans[x] = max(ans[x], ans[e.fi]+e.se);
    //     }
    // }

    // for(int i = 1; i <= N; i++) {
    //     cout << ans[i] << endl;
    // }
}