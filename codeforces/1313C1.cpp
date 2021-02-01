// https://codeforces.com/contest/1313/problem/C1

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

const int maxn = 1050;

int n;
int a[maxn], ans[maxn];

int go(int ind) {
    ans[ind] = a[ind];
    for(int i = ind-1; i >= 1; i--) {
        ans[i] = min(a[i], ans[i+1]);
    }

    for(int i = ind+1; i <= n; i++) {
        ans[i] = min(a[i], ans[i-1]);
    }

    int sum = 0;
    for(int i = 1; i <= n; i++) sum += ans[i];

    return sum;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ma = 0, maiind = -1;
    for(int i = 1; i <= n; i++) {
        int loc = go(i);
        if(loc > ma) {
            ma = loc;
            maiind = i;
        }
    }

    go(maiind);

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
