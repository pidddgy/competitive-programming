// https://codeforces.com/contest/722/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

int N;
const int maxn = 100500;

int a[maxn];
int b[maxn];
int dsu[maxn];
bool added[maxn];
int sz[maxn];
int ans[maxn];

int findp(int n) {
    if(dsu[n] != n) {
        return dsu[n] = findp(dsu[n]); 
    }
    return n;
}

void merge(int u, int v) {
    u = findp(u);
    v = findp(v);

    dsu[u] = v;
    sz[v] += sz[u];
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= N; i++) {
        cin >> b[i];
        dsu[i] = i;
    }

    int cur = 0;
    for(int i = N; i >= 1; i--) {
        sz[b[i]] = a[b[i]];

        if(b[i] > 1) {
            if(added[b[i]-1]) {
                merge(b[i], b[i]-1);
            }
        }

        if(b[i] < N) {
            if(added[b[i]+1]) {
                merge(b[i], b[i]+1);
            }
        }

        added[b[i]] = true;
        ans[i] = cur;

        cur = max(cur, sz[findp(b[i])]);
    }

    for(int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
}