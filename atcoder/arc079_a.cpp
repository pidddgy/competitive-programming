// https://atcoder.jp/contests/arc079/tasks/arc079_a

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

const int maxn = 200500;

vector<int> G[maxn];
int N, M;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    while(M--) {
        int u, v;
        cin >> u >> v;

        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    string ans = "IMPOSSIBLE";
    for(int adj: G[1]) {
        for(int adj2: G[adj]) {
            if(adj2 == N) {
                ans = "POSSIBLE";
            }
        }
    }

    cout << ans << endl;
}