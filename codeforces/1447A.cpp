// https://codeforces.com/contest/1447/problem/0

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

int trng(int n) {
    return (n*(n+1))/2;
}

void solve() {
    int n;
    cin >> n;

    // vector<int> a(n+1);
    // for(int i = 1; i <= n; i++) a[i] = i;

    // int add = n-1;

    // for(int i = 1; i <= n; i++) {
    //     a[i] += trng(add);
    // }

    // for(int i = 2; i <= n; i++) {
    //     a[i] -= i-1;
    // }

    // for(int i = 1; i <= n; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    cout << n-1 << endl;
    for(int i = 2; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;
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

add trng(m) to all

subtract

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
