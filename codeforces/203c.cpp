// https://codeforces.com/contest/350/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 100500;

pii a[maxn];

bool comp(pii l, pii r) {
    return abs(l.fi)+abs(l.se) < abs(r.fi) + abs(r.se);
}

struct op {
    int type, amt;
    char di;

    op(int typee, char dii, int amtt) {
        type = typee;
        amt = amtt;
        di = dii;
    }
};


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;   

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    sort(a+1, a+n+1, comp);

    vector<op> ans;
    pii cur = {0, 0};
    for(int i = 1; i <= n; i++) {
        if(a[i].fi > cur.fi) {
            ans.emplace_back(1, 'R', a[i].fi-cur.fi);
        } else if(a[i].fi < cur.fi) {
            ans.emplace_back(1, 'L', cur.fi-a[i].fi);
        }

        if(a[i].se > cur.fi) {
            ans.emplace_back(1, 'U', a[i].se-cur.se);
        } else if(a[i].se < cur.se) {
            ans.emplace_back(1, 'D', cur.se-a[i].se);
        }

        cur = a[i];

        ans.emplace_back(2, '?', -1);

        if(0 > cur.fi) {
            ans.emplace_back(1, 'R', 0-cur.fi);
        } else if(0 < cur.fi) {
            ans.emplace_back(1, 'L', cur.fi-0);
        }

        if(0 > cur.se) {
            ans.emplace_back(1, 'U', 0-cur.se);
        } else if(0 < cur.se) {
            ans.emplace_back(1, 'D', cur.se-0);
        }
        ans.emplace_back(3, '?', -1);
        cur = {0, 0};

    }

    cout << ans.size() << endl;
    for(op x: ans) {
        cout << x.type << " ";
        if(x.type == 1) cout << x.amt << " " << x.di;

        cout << endl;
    }
}