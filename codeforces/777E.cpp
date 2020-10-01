// https://codeforces.com/contest/777/problem/E

#include <bits/stdc++.h>
using namespace std;
#define cerr cout
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ll long long

ll N;

// Coordinate compression
ll coord = 1;
set<ll> S;
map<ll, ll> vals;

struct ring {
    ll a, b, h;
    
    ring(ll aa, ll bb, ll hh) {
        a = aa;
        b = bb;
        h = hh;
    }
};

struct Compare {
    bool operator()(ring &l, ring &r) {
        if(l.b == r.b) {
            return l.a < r.a;
        } else {
            return l.b < r.b; 
        }
    }
};

ll seg[800100];

void upd(ll pos, ll val, ll ind=1, ll cl=1, ll cr=2e5) {
    if(cl == cr) {
        seg[ind] = val;
    } else {
        ll cm = (cl+cr)/2;
        if(pos <= cm) {
            upd(pos, val, ind*2, cl, cm);
        } else {
            upd(pos, val, ind*2+1, cm+1, cr);
        }

        seg[ind] = max(seg[ind*2], seg[ind*2+1]);
    }
}

ll query(ll l, ll r, ll ind=1, ll cl=1, ll cr=2e5) {
    if(l > r) {
        return 0;
    }
    
    if(cl == l and cr == r) {
        return seg[ind];
    }

    ll cm = (cl+cr)/2;
    return max(query(l, min(cm, r), ind*2, cl, cm),
            query(max(l, cm+1), r, ind*2+1, cm+1, cr));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for(ll i = 1; i <= 1e5; i++) {
        upd(i, 0);
    }


    vector<ring> rings;
    for(ll i = 1; i <= N; i++) {
        ll a, b, h;
        cin >> a >> b >> h;
        a++;

        S.emplace(a);
        S.emplace(b);

        rings.emplace_back(a, b, h);
    }

    for(ll x: S) {
        vals[x] = coord;
        coord++;
    }

    // Rings with compressed values
    vector<ring> cr;

    for(ring r: rings) {
        cr.emplace_back(vals[r.a], vals[r.b], r.h);
    }

    sort(cr.begin(), cr.end(), Compare());

    ll ans = 0;
    for(ring r: cr) {
        ll x = query(r.a, r.b);
        x += r.h;

        ans = max(ans, x);

        upd(r.b, x);
    }

    cout << ans << endl;
}