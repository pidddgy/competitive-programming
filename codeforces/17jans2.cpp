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
char a[maxn];
map<char, int> pre[maxn];
map<char, int> suf[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<char, int> mp;
    for(int i = 1; i <= n; i++) {
        mp[a[i]]++;

        pre[i] = mp;
    }

    mp.clear();
    for(int i = n; i >= 1; i--) {
        mp[a[i]]++;

        suf[i] = mp;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, max({pre[i-1]['P'], pre[i-1]['H'], pre[i-1]['S']}) + 
                        max({suf[i]['P'], suf[i]['H'], suf[i]['S']}));
    }

    cout << ans << endl;
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
