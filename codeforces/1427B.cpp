// https://codeforces.com/contest/1427/problem/B

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

const int maxn = 200500;

string s;

void solve() {
    int n, k;
    cin >> n >> k;
    cin >> s;

    s = "."+s;

    vector<int> ranges;

    int base = 0;
    int fw = n+1;
    for(int i = n; i >= 1; i--) {
        if(s[i] == 'W') {
            fw = i;
            base++;
            if(i > 1 and s[i-1] == 'W') {
                base++;
            }
        }
    }

    if(fw == n+1) {
        cout << max(0LL, 2*k-1) << endl;
        return;
    }

    int l = -1;
    for(int i = fw; i <= n; i++) {
        if(s[i] == 'L' and l == -1) {
            l = i;
        }

        if(s[i] == 'W' and l != -1) {
            ranges.emplace_back(i-l);
            l = -1;
        }
    }

    sort(all(ranges));
    int ans = 0;
    for(int x: ranges) {
        cerr << "using " << x << endl;
        int take = min(k, x);
        if(take == x) ans += 2*take+1;
        else ans += 2*take;
        k -= take;
    }

    if(l != -1) {
        int x = n+1-l;
        int take = min(k, x);

        cerr << "using " << take << " at end" << endl;

        ans += 2*take;

        k -= take;
    }
    

    if(fw > 1) {
        int x = fw-1;

        int take = min(k, x);

        cerr << "using " << take << " at beginning" << endl;

        ans += max(0LL, 2*take);
        k -= take;
    }

    watch(base)
    watch(ans)

    cout << base+ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

we want to join as many runs as possible

if we still have any pick index with one before it

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?