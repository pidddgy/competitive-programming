#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
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

int n;
int a[maxn], sorted[maxn];
map<int, int> mp;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("sort.in", "r", stdin); 
    freopen("sort.out", "w", stdout);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
        mp[a[i]] = 1e18;
    }

    sort(sorted+1, sorted+n+1);
    for(int i = 1; i <= n; i++) {
        mp[sorted[i]] = min(mp[sorted[i]], i);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, i-mp[a[i]]);
        mp[a[i]]++;
    }

    cout << ans+1 << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
