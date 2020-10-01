// https://codeforces.com/contest/1032/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define ld long double
#define pld pair<ld, ld>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
ld a, b, c;
ld sx, sy, ex, ey;

ld ham(ld x1, ld y1, ld x2, ld y2) {
    return fabs(x1-x2) + fabs(y1-y2);
}

ld sq(ld n) {
    return n*n;
}

ld euc(ld x1, ld y1, ld x2, ld y2) {
    ld h = fabs(x1-x2);
    ld w = fabs(y1-y2);

    return sqrt(sq(h)+sq(w));
}

bool in(ld x, ld y) {
    if(min(sx, ex) <= x and x <= max(sx, ex) ) {
        if(min(sy, ey) <= y and y <= max(sy, ey)) {
            return true;
        }
    }

    return false;
}

// Cannot use diagonal / not worth to use line
void no() {
    cerr << "no" << endl;
    cout << ham(sx, sy, ex, ey) << endl;
    exit(0);
}

set<pld> points;
const ld EPS = 1e-8;

bool same(ld n, ld m) {
    return fabs(n-m) < EPS;
}

bool dup(pld p) {
    for(pld o: points) {
        if(same(p.fi, o.fi) and same(p.se, o.se)) {
            return true;
        }
    } 

    return false;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    cout << fixed << setprecision(10);

    cin >> a >> b >> c;
    cin >> sx >> sy >> ex >> ey;

    ld slope;
    if(b == 0 or a == 0) {
        no();
    } else {
        slope = -a/b;
    }

    ld intercept = -c/b;

    // Fix x
    for(ld x: set<ld>({sx, ex})) {
        if(in(x, x*slope+intercept) and !dup(pld(x, x*slope+intercept))) {
            points.emplace(x, x*slope+intercept);
        }
    }

    // Fix y
    for(ld y: set<ld>({sy, ey})) {
        if(in((y-intercept)/slope, y) and !dup(pld((y-intercept)/slope, y))) {
            points.emplace((y-intercept)/slope, y);
        }
    }

    if(points.size() < 2) {
        no();
    }

    assert(points.size() == 2);

    vector<pld> pvctr;

    for(pld p: points) {
        pvctr.emplace_back(p);
    }

    ld ans = ham(sx, sy, ex, ey);

    ans = min(ans, ham(sx, sy, pvctr[0].fi, pvctr[0].se) +
                euc(pvctr[0].fi, pvctr[0].se, pvctr[1].fi, pvctr[1].se) + 
                ham(pvctr[1].fi, pvctr[1].se, ex, ey));

    swap(pvctr[0], pvctr[1]);
    ans = min(ans, ham(sx, sy, pvctr[0].fi, pvctr[0].se) +
                    euc(pvctr[0].fi, pvctr[0].se, pvctr[1].fi, pvctr[1].se) + 
                    ham(pvctr[1].fi, pvctr[1].se, ex, ey));
    
    cout << ans << endl;
} 
