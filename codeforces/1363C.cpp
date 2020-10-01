// https://codeforces.com/contest/1363/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 1005;

int deg[maxn];

void clear() {
    for(int i = 0; i < maxn; i++) {
        deg[i] = 0;
    }
}

void solve() {
    int n, x;
    cin >> n >> x;

    for(int i = 1; i <= n-1; i++) {
        int u, v;
        cin >> u >> v;  

        deg[u]++;
        deg[v]++;
    }

    if(deg[x] <= 1) {
        cout << "Ayush" << endl;
    } else if((n-1) % 2 == 1) {
        cout << "Ayush" << endl;
    } else {
        cout << "Ashish" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        clear();
        solve();
    }
}
