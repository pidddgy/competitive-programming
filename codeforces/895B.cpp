// https://codeforces.com/contest/895/problem/B

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

const int maxn = 100500;

int a[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, x, k;
    cin >> n >> x >> k;

    map<int, int> acnt;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        acnt[a[i]]++;
    }

    int ind = 0;
    vector<pii> v;
    for(pii x: acnt) v.emplace_back(x);

    sort(a+1, a+n+1);

    map<int, int> cnt;
    int ans = 0;
    
    for(int i = 1; i <= n; i++) {
        while(ind < v.size() and v[ind].fi <= a[i]) {
            cnt[(v[ind].fi-1)/x] += v[ind].se;
            ind++;
        }

        int val = a[i]/x;
        int desired = val - k;

        ans += cnt[desired];
    }

    cout << ans << endl;
}

/*

iterate over each element
    consider each element as an r

    update cnt[(val-1)/x] as needed

    let val = element/x
    let desired = val - k
    ans += cnt[desired]


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
