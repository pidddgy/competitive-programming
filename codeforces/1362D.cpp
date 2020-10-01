// https://codeforces.com/contest/1362/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 500500;

set<int> G[maxn];
int p[maxn];
int cur[maxn];

void no() {
    cout << -1 << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        G[a].emplace(b);
        G[b].emplace(a);
    }

    pii a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        a[i] = pii(p[i], i);
    }

    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i++) {
        pii x = a[i];
        set<int> S;
        for(int adj: G[x.se]) {
            S.emplace(cur[adj]);
        }

        for(int j = 1; j < p[x.se]; j++) {
            if(!S.count(j)) {
                no();
            }
        }

        if(S.count(x.fi)) {
            no();
        }

        cur[x.se] = x.fi;
    }

    for(int i = 1; i <= n; i++) {
        cout << a[i].se << " ";
    }
    cout << endl;
}
