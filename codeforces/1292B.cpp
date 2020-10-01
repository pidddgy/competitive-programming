// https://codeforces.com/problemset/problem/1292/B

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

const int inf = (int)1e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x_0, y_0, ax, ay, bx, by;
    cin >> x_0 >> y_0 >> ax >> ay >> bx >> by;

    int x, y, t;
    cin >> x >> y >> t;

    vector<pii> nodes;
    nodes.emplace_back(x_0, y_0);
    int lx = x_0, ly = y_0;

    for(int i = 2; i <= 1000; i++) {
        watch(i)
        pii emp = {-1, -1};
        if(lx <= inf / ax) {
            // hopefully adding is ok
            emp.fi = ax * lx + bx;
            lx = ax * lx + bx;
        } else break;
        
        if(ly <= inf / ay) {
            emp.se = ay * ly + by;
            ly = ay * ly + by;
        } else break;

        nodes.emplace_back(emp);
    }

    for(pii p: nodes) {
        cerr << p.fi << " " << p.se << endl;
    }

    assert(sz(nodes) <= 1000);

    int ans = 0;
    for(int i = 0; i < sz(nodes); i++) {
        for(int j = i; j < sz(nodes); j++) {
            // go to left point first, then right
            int cost = 0;

            // get to left point
            cost += abs(x-nodes[i].fi) + abs(y-nodes[i].se);
            
            // go from left point to right
            cost += abs(nodes[j].fi-nodes[i].fi) + abs(nodes[j].se-nodes[i].se);

            if(cost <= t) {
                ans = max(ans, j-i+1);
            }

            // go to right point first, then left
            cost = 0;

            // go to right point
            cost += abs(x-nodes[j].fi) + abs(y-nodes[j].se);

            // go from right point to left point
            cost += abs(nodes[i].fi-nodes[j].fi) + abs(nodes[i].se-nodes[j].se);

            if(cost <= t) {
                ans = max(ans, j-i+1);
            }
        }
    }

    cout << ans << endl;
}

/*

the maximum point we can ever go up to is 20 ^ 16

create all points so that both points are <= 10^18, use division trick to not overflow

there should be like less than 100 or something

brute force a contiguous subarray to use
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
