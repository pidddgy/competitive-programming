// https://codeforces.com/contest/1093/problem/D

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define cerr if(false) cerr
#define int long long
const int maxn = (3*1e5)+500;
const int MOD =  998244353;


int modpow(int a, int exp){
    if(exp == 0) return 1;
    int t = modpow(a,exp/2);
    if(exp%2) return t*t%MOD*a%MOD;
    return t*t%MOD;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<int> G[n+1];

        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;

            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }

        int color[n+1];
        for(int i = 1; i <= n; i++) color[i] = -1;

        int ans = 1;
        bool dont = false;
        for(int st = 1; st <= n; st++) {
            if(color[st] == -1) {
                bool bipartite = true;
                int o = 0;
                int z = 0;
                queue<int> Q;
                Q.push(st);
                color[st] = 0;
                z++;

                while(!Q.empty()) {
                    int S = Q.front(); Q.pop();

                    for(int adj: G[S]) {
                        if(color[adj] == -1) {
                            if(color[S] == 0) {
                                color[adj] = 1;
                                o++;
                            } else {
                                color[adj] = 0;
                                z++;
                            }
                            Q.push(adj);
                        } else {
                            if(color[S] == color[adj]) {
                                bipartite = false;
                            }
                        }
                    }
                }

                if(bipartite) {
                    watch(z)
                    watch(o)
                    // ans *= (((int)pow(2, z) % MOD + (int)pow(2, o) % MOD));
                    ans *= modpow(2, z) + modpow(2, o);
                    ans %= MOD;
                } else {
                    dont = true;
                }
            }

          
        }

        if(dont) cout << 0 << endl;
        else cout << ans << endl;

    }
}