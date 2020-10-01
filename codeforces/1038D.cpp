// https://codeforces.com/problemset/problem/1038/D

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

const int maxn = 500500;

int n;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    if(n == 1) {
        cout << a[1] << endl;
        return 0;
    }

    int mi = INT_MAX, ans = 0;
    bool neg = false, pos = false;
    for(int i = 1; i <= n; i++) {
        mi = min(mi, abs(a[i]));

        if(a[i] < 0) {
            neg = true;   
        }

        if(a[i] > 0) {
            pos = true;
        }

        ans += abs(a[i]);
    }

    if(neg and pos) {
        cout << ans << endl;
    } else {
        cout << ans - 2*mi << endl;
    }


}

/*

we want to maximize the last element
so we want to minimize or maximize the second last element

best to create least elements and join them

naive dp (n^2):
    dp[l][r] = lowest we can join l, r into

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
