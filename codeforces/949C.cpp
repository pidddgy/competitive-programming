// https://codeforces.com/contest/949/problem/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
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

const int maxn = 100500;

int n, m, h;
int u[maxn];
int disj[maxn];
vector<int> c[maxn];
vector<int> G[maxn];

int findp(int v) {
    if(disj[v] == v) return v;
    return disj[v] = findp(disj[v]);
}

void merge(int a, int b) {
    int x = findp(a);
    int y = findp(b);

    disj[x] = y;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> h;
    for(int i = 1; i <= n; i++) {
        cin >> u[i];
        disj[i] = i;
    }

    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        merge(u, v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    // try to make 1
    for(int i = 1; i <= n; i++) {
        set<int> S;
        cerr << "on " << i << endl;
        for(int x: G[i]) {
            cerr << x << " " << u[x] << endl;
            S.emplace(u[x]);
        }

        if(!S.count((u[i]+1)%h)) {
            // cerr << "using " << x << ", we do not have " << (u[x]+1)%h << endl;
            cout << 1 << endl;
            cout << i << endl;
            exit(0);
        }
    }

    for(int i = 1; i <= n; i++) {
        // cerr << "emplacing " << i << " to " << findp(i) << endl;
        c[findp(i)].emplace_back(i);
    }

    int mi = LLONG_MAX;
    for(int i = 1; i <= n; i++) {
        if(c[i].empty()) continue;
        mi = min(mi, sz(c[i]));
    }

    for(int i = 1; i <= n; i++) {
        if(sz(c[i]) == mi) {
            cout << mi << endl;

            for(int j =0 ; j < sz(c[i]); j++) {
                cout << c[i][j];
                if(j != sz(c[i])-1) cout << " ";
            }
            cout << endl;
            exit(0);
        }
    }

    cout << "none" << endl;
    assert(false);
}

/*

restate

pick some non empty subset and increment 1, maintaining the condition that no two clients have both data centers with same maintenance time

bound: increment all

create graph where edge (u, v) means that data center u cannot be the same as data center v
increment minimal subset so that each node is not same as any nodes it has direct connection to (above graph)

each node is a sequence ofintegers

guess: 1 or n

construct case where we increment 2



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
