// https://codeforces.com/contest/1013/problem/D

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

int disj[2*maxn];
bool par[2*maxn];

int findp(int v) {
    if(disj[v] == v) return v;
    else return disj[v] = findp(disj[v]);
}

void merge(int a, int b) {
    int c = findp(a);
    int d = findp(b);

    disj[c] = d;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 2*maxn; i++) disj[i] = i;

    int n, m, q;
    cin >> n >> m >> q;

    while(q--) {
        int r, c;
        cin >> r >> c;

        c += n;

        merge(findp(r), findp(c));
    }

    for(int i = 1; i <= n+m; i++) {
        par[findp(i)] = true;
    }

    int cum = 0;
    for(int i = 1; i <= n+m; i++) {
        cum += par[i];
    }

    cout << cum-1 << endl;
}

/*

consider as components you merge

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
