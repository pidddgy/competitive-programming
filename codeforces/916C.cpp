// https://codeforces.com/contest/916/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

struct edge {
    int u, v, w;

    edge(int uu, int vv, int ww) {
        u = uu;
        v = vv;
        w = ww;
    }
};
const int maxn = 100500;

int n, m;
int prime[500000];
set<int> primes;
vector<edge> ans;
set<int> G[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 500000-100; i++) {
        prime[i] = true;
    }
    for(int p = 2; p <= 500000-100; p++) {
        if(prime[p]) {
            for(int i = p*p; i <= 500000-100; i += p) {
                prime[i] = false;
            }
        }
    }

    for(int i = 2; i <= 500000-100; i++) {
        if(prime[i]) {
            primes.emplace(i);
        }
    }

    cin >> n >> m;

    int mstw = 0;
    for(int i = 1; i <= n-2; i++) {
        ans.emplace_back(i, i+1, 1);
        mstw++;
        G[i].emplace(i+1);
        G[i+1].emplace(i);
    }

    int need = *primes.upper_bound(mstw);
    watch(need)

    ans.emplace_back(n-1, n, need-mstw);
    G[n-1].emplace(n);
    G[n].emplace(n-1);

    mstw += need;

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(!G[i].count(j)) {
                ans.emplace_back(i, j, 1e9);
            }
            if(ans.size()==m) break;
        }
        if(ans.size()==m) break;
    }

    cout << need << " " << need << endl;
    for(edge e: ans) {
        cout << e.u << " " << e.v << " " << e.w << endl;
    }
}