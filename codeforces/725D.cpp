// https://codeforces.com/contest/725/problem/D

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

const int maxn = 300500;

pii a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        a[i].se = (a[i].se-a[i].fi)+1;
        watch(a[i].se)
    }

    sort(a+2, a+n+1, greater<pii>());

    priority_queue<int> pq;

    int cur = 2;
    while(cur <= n and a[1].fi < a[cur].fi) {
        cerr << "pushing " << -a[cur].se << endl;
        pq.push(-a[cur].se);
        cur++;
    }

    int ans = sz(pq)+1;
    watch(ans)
    while(!pq.empty()) {
        int x = pq.top(); pq.pop();
        a[1].fi += x;
        watch(x)
        if(a[1].fi < 0) break;
        watch(a[1].fi)
        while(cur <= n and a[1].fi < a[cur].fi) {
            pq.push(-a[cur].se);
            cur++;
        }

        ans = min(ans, sz(pq)+1);
    }

    cout << ans << endl;
}

/*

sort teams by number of balloons

take all the teams that are above our team

sort those teams by number of balloons it would take to disqualify them

disqualify as many of them as possible

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
