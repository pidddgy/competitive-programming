// https://codeforces.com/contest/1398/problem/C

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

const int maxn = 100500;
int a[maxn];
void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    for(int i = 1; i <= n; i++) {
        a[i] = s[i-1]-'0';
        a[i]--;
        cerr << a[i] << " ";
    }
    cerr << endl;

    int cur = 0;
    // proabbly a way to do this w/out adding log factor but whatever
    int ans = 0;
    map<int, int> cnt;
    cnt[0] = 1;
    for(int i = 1; i <= n; i++) {
        cur += a[i];

        cerr << "adding " << cnt[cur] << " on " << i << ", cur is " << cur << endl;
        ans += cnt[cur];
        cnt[cur]++;    
    }

    cout << ans << endl;

    for(int i = 1; i <= n; i++) {
        a[i] = 0;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}

/*

keep track of current cnt

get count of however many subarrays we can subtract to get length

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
