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

const int maxn = (int)1e6+500;

int n;
int a[maxn];

// function for prefix/suffix
int pre[maxn], suf[maxn];

int bit[maxn];

int sum(int pos) {
    int res = 0;
    for(int i = pos; i >= 1; i -= (i & -i)) {
        res += bit[i];
    }

    return res;
}

void inc(int pos) {
    for(int i = pos; i <= n; i += (i & -i)) {
        bit[i]++;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, int> cnt;

    for(int i = 1; i <= n; i++) {
        cnt[a[i]]++;
        pre[i] = cnt[a[i]];
    }

    cnt.clear();
    for(int i = n; i >= 1; i--) {
        cnt[a[i]]++;
        suf[i] = cnt[a[i]];
    }

    int ans = 0;
    for(int i = n; i >= 1; i--) {
        ans += sum(pre[i]-1);
        inc(suf[i]);
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
