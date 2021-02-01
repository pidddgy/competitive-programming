// https://codeforces.com/contest/883/problem/K

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

const int maxn = 200500;

int n;
int l[maxn], r[maxn], sufmi[maxn], sufma[maxn], ans[maxn];

void no() {
    cout << -1 << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int s, g;
        cin >> s >> g;

        l[i] = s;
        r[i] = s+g;
    }

    int ma = LLONG_MIN;
    for(int i = n; i >= 1; i--) {
        ma = max(ma, l[i]-i+1);
        sufma[i] = ma;
    }

    int mi = LLONG_MAX;
    for(int i = n; i >= 1; i--) {
        mi = min(mi, r[i]+i-1);
        sufmi[i] = mi;
    }

    int sum = 0;
    for(int i = 1; i <= n; i++) {
        int lb = l[i], rb = r[i];

        if(i > 1) {
            lb = max(lb, ans[i-1]-1);
            rb = min(rb, ans[i-1]+1);
        }

        if(i < n) {
            lb = max(lb, sufma[i+1]+i-1);
            rb = min(rb, sufmi[i+1]-i+1);
        }

        if(lb > rb) no();

        ans[i] = rb;

        sum += ans[i]-l[i];
    }

    for(int i = 2; i <= n-1; i++) {
        for(int x: set<int>({1, -1})) {
            assert(abs(ans[i]-ans[i+x]) <= 1);
        }
    }

    cout << sum << endl;
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

given n ranges from l to r, pick a number for each range so that inequality is satisfied and sum is minimized

set a[i] = l[i]-i+1
store suffix max 

make sure to add current index - 1

if any of them don't overlap print -1


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
