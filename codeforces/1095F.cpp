// https://codeforces.com/contest/1095/problem/F

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define cerr if(false) cerr
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 200500;

int n, m;

pii a[maxn];

// o -> list of offers, fi = cost, .se = nodes
vector<pair<int, pii>> o;
int disj[maxn];

int findp(int n) {
    if(disj[n] == n) return n;
    else return disj[n] = findp(disj[n]);
}

void merge(int x, int y) {
    int xp = findp(x), yp = findp(y);

    disj[xp] = yp;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < maxn; i++) {
        disj[i] = i;
    }

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }

    for(int i = 1; i <= m; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        o.push_back({w, pii(x, y)});
    }

    sort(o.begin(), o.end());
    sort(a+1, a+n+1);

    int ans = 0;
    int ind = 0;
    for(int i = 2; i <= n; i++) {
        if(findp(a[1].se) == findp(a[i].se)) continue;
        int cost = a[1].fi + a[i].fi;

        while(ind < o.size() and o[ind].fi < cost) {
            if(findp(o[ind].se.fi) != findp(o[ind].se.se)) {
                merge(o[ind].se.fi, o[ind].se.se);
                ans += o[ind].fi;
            }
            ind++;
        }

        if(findp(a[1].se) == findp(a[i].se)) continue;
        ans += cost;
        merge(a[1].se, a[i].se);
    }
    
    cout << ans << endl;
}
