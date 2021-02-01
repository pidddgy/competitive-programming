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

const int maxn = 500500;
int n, m, k, q;

vector<int> blocks[maxn];
vector<pair<pii, int>> p[maxn];

int disj[3*maxn];

int findp(int v) {
    if(disj[v] == v) return v;
    return disj[v] = findp(disj[v]);
}

void merge(int a, int b) {
    int c = findp(a);
    int d = findp(b);

    disj[c] = d;
}

int getid(int r, int c) {
    int lo = 0, hi = sz(p[c])-1;

    while(lo <= hi) {
        int mid = (lo+hi)/2;

        pii x = p[c][mid].fi;

        if(x.fi <= r and r <= x.se) return p[c][mid].se;
        else if(r > x.se) {
            // higher
            lo = mid+1;
        } else if(r < x.fi) {
            hi = mid-1;
        }
    }

    // assert(false);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 3*maxn; i++) disj[i] = i;

    cin >> n >> m >> k >> q;

    for(int i = 1; i <= k; i++) {
        int r, c;
        cin >> r >> c;

        blocks[c].emplace_back(r);
        cerr << "emplacing " << r << " to " << c << endl;
    }

    int id = 0;
    for(int i = 1; i <= m; i++) {
        blocks[i].emplace_back(n+1);
        sort(all(blocks[i]));
        int lst = 0; // last block
        for(int x: blocks[i]) {
            if(x-lst > 1) {
                p[i].emplace_back(pii(lst+1, x-1), ++id);
                // assert(id <= 2*maxn);
            }
            lst = x;
        }
        // assert(sz(p[i]));

        // for(pii x: p[i]) {
        //     cerr << x.fi << " " << x.se << endl;
        // }
        // cerr << endl;
    }

    for(int i = 1; i <= m-1; i++) {
        int cur = 0;
        if(p[i].empty()) continue;
        for(auto x: p[i+1]) {
            while(cur+1 < sz(p[i]) and (p[i][cur].fi.se < x.fi.fi)) cur++;

            if(p[i][cur].fi.fi <= x.fi.fi and p[i][cur].fi.se >= x.fi.fi) {

                cerr << "" << p[i][cur].se << " " << x.se << endl;
                merge(p[i][cur].se, x.se);
            }
        }
    }

    for(int i = m; i >= 2; i--) {
        int cur = 0;
        if(p[i].empty()) continue;

        for(auto x: p[i-1]) {
            while(cur+1 < sz(p[i]) and (p[i][cur].fi.se < x.fi.fi)) cur++;

            if(p[i][cur].fi.fi <= x.fi.fi and p[i][cur].fi.se >= x.fi.fi) {
                cerr << "" << p[i][cur].se << " " << x.se << endl;
                merge(p[i][cur].se, x.se);
            }
        }
    }

    while(q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        watch(getid(r1, c1))
        watch(getid(r2, c2))
        if(findp(getid(r1, c1)) == findp(getid(r2, c2))) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

/*

think of each column as rows

at most K induvidual

have vector<pii> for each column

for i in 1...n-1
    let cur = 0
    for j in all pairs
        try connecting j to cur




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
