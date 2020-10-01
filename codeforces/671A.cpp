// https://codeforces.com/problemset/problem/671/A

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define pld pair<ld, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

int sq(int x) {
    return x*x;
}
ld eucdis(ld x1, ld y1, ld x2, ld y2) {
    return sqrt(sq(abs(x1-x2)) + sq(abs(y1-y2)));
}

const int maxn = 100500;

pld a[maxn];
ld cost[maxn];
ld costa[maxn], costb[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(23);
    cout << fixed << setprecision(23);

    ld ax, ay, bx, by, tx, ty;
    cin >> ax >> ay >> bx >> by >> tx >> ty;

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
         cin >> a[i].fi >> a[i].se;
    }

    ld tot = 0;

    vector<pld> rema, remb;

    for(int i = 1; i <= n; i++) {
        cost[i] = 2.0*eucdis(tx, ty, a[i].fi, a[i].se);
        tot += cost[i];

        costa[i] = eucdis(ax, ay, a[i].fi, a[i].se) + eucdis(tx, ty, a[i].fi, a[i].se);
        costb[i] = eucdis(bx, by, a[i].fi, a[i].se) + eucdis(tx, ty, a[i].fi, a[i].se);

        rema.emplace_back(cost[i]-costa[i], i);
        remb.emplace_back(cost[i]-costb[i], i);
    }

    sort(all(rema), greater<pld>());
    sort(all(remb), greater<pld>());

    ld ans1 = tot, ans2 = tot;

    // prioritize rema

    int take = rema[0].se;
    ans1 -= rema[0].fi;

    for(int i = 0; i < sz(remb); i++) {
        if((remb[i].se != take) and (remb[i].fi > 0)) {
            ans1 -= remb[i].fi;
            break;
        }
    }

    // prioritize b
    take = remb[0].se;
    ans2 -= remb[0].fi;

    for(int i = 0; i < sz(rema); i++) {
        if((rema[i].se != take) and (rema[i].fi > 0)) {
            ans2 -= rema[i].fi;
            break;
        }
    }

    cout << min(ans1, ans2) << endl;
}

/*

think of one person that can starts at a or b, and can teleport to the other before going to any

every single time we start from recycling bin, go to bottle, and go back
pick 2 bottles where instead of starting from recycling bin we start from a/b

either we prioritize a or we prioritize b

use prefix sums

for i in in 1...n
    calculate distance from recycling bin to bottle and back
    calculate distance from a to i and back
    calculate distance from b to i and back

get total distance

get two best bottles to remove for a and b

remove best for a

if best for b is same as a, then remove second
else remove best

repeat same process but flip a/b


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
