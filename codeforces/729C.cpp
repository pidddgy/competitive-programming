// https://codeforces.com/contest/729/problem/C

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

void no() {
    cout << -1 << endl;
    exit(0);
}

const int maxn = 200500;

int c[maxn], v[maxn];

int n, k, s, t;
vector<int> costs;
vector<int> stations;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> s >> t;

    for(int i = 1; i <= n; i++) {
        cin >> c[i] >> v[i];
    }

    for(int i = 1; i <= k; i++) {
        int g;
        cin >> g;

        stations.emplace_back(g);
    }

    sort(all(stations));
    int l = 0, r = 2e9;
    int lgood = -1;

    int last = 0;
    for(int g: stations) {
        costs.emplace_back(g-last);
        l = max(l, g-last);
        last = g;
    }
    costs.emplace_back(s-last);

    l = max(l, s-last);

    int needed = max(0LL, 2*s-t);

    // binary search for minimum max edge cost
    while(l <= r) {
        int mid = (l+r)/2;
        int taken = 0;
        for(int c: costs) {
            // length is equal to initial cost
            taken += max(0LL, min(c, mid-c));
        }

        if(taken >= needed) {
            lgood = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }

    if(lgood == -1) no();

    int ans = LLONG_MAX;
    for(int i = 1; i <= n; i++) {
        if(v[i] >= lgood) {
            ans = min(ans, c[i]);
        }
    }

    if(ans == LLONG_MAX) no();

    cout << ans << endl;
}

/*

consider the gaps in between start -> gas station -> gas station -> end

there is a fixed amount of times we must use accelerated

have an edge class which has:
    - u
    - v
    - cost
    - current amount of accelerations used

maintain max cost
push into set. for each acceleration needed put it into the edge with least cost. increment cost and accelerations by 1. if accelerations used is equal to the length of the road do not push. update max cost

we always want to use the edge with least cost whenever possible. if an optimal solution puts accelerations into a longer road when a smaller road is possible, we can exchange the two to create a better or equal solution. thus our greedy solution works

binary search for minimum possible cost

1000000000
2000000000

999999999
999999998
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
