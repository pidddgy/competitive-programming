// https://codeforces.com/contest/1253/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 200500;

int n, m;
set<int> G[maxn];
int disj[maxn];
int ma[maxn];
bool skip[maxn];

int findp(int n) {
    if(disj[n] == n) return n;
    else return disj[n] = findp(disj[n]);
}

// merges b into a's component
void merge(int a, int b) {
    int c = findp(a);
    int d = findp(b);

    if(c == d) return;

    disj[min(c, d)] = max(c, d);
    ma[max(c, d)] = max(ma[min(c, d)], ma[max(c, d)]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        disj[i] = i;
        ma[i] = i;
    }

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        merge(u, v);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(skip[i]) continue;
        for(int j = i; j <= ma[findp(i)]; j++) {
            if(findp(i) != findp(j)) {
                merge(i, j);
                ans++;
            }
            skip[j] = true;
        }
    }

    cout << ans << endl;
}
