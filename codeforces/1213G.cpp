// https://codeforces.com/contest/1213/problem/G

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

struct Edge {
    int u, v, w;

    Edge(int uu, int vv, int ww) {
        u = uu;
        v = vv;
        w = ww;
    }
};

bool cmp(Edge l, Edge r) {
    return l.w < r.w;
}

const int maxn = 200500;

vector<Edge> edges;
int n, m;

int disj[maxn], car[maxn];

int findp(int v) {
    if(disj[v] == v) return v;
    else {
        return disj[v] = findp(disj[v]);
    }
}

void merge(int a, int b) {
    int c = findp(a);
    int d = findp(b);

    car[d] += car[c];
    disj[c] = d;
}

int trng(int num) {
    return (num*(num+1))/2;
}

pii queries[maxn];
int ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        car[i] = 1;
        disj[i] = i;
    }

    for(int i = 1; i <= n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        edges.emplace_back(u, v, w);
    }

    for(int i = 1; i <= m; i++) {
        cin >> queries[i].fi;
        queries[i].se = i;
    }

    sort(queries+1, queries+m+1);

    // chepaest edges go in back
    sort(all(edges), cmp);
    reverse(all(edges));

    int cur = 0;
    for(int i = 1; i <= m; i++) {
        while(sz(edges) and edges.back().w <= queries[i].fi) {
            Edge e = edges.back();
            cerr << e.u << " " << e.v << " " << e.w << endl;
            cur -= trng(car[findp(e.u)]-1);
            cur -= trng(car[findp(e.v)]-1);
            cerr << "joining two components of size " << car[findp(e.u)] << " and " << car[findp(e.v)] << endl;
            merge(e.u, e.v);
            cur += trng(car[findp(e.u)]-1);
            watch(car[4])
            edges.pop_back();
        }

        ans[queries[i].se] = cur;
    }

    for(int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

think of components that are split

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
