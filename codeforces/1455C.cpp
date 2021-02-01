// https://codeforces.com/contest/1455/problem/C

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

// x-y on current turn
int dp[(int)1e6+500];

void solve() {
    vector<int> a(2);

    cin >> a[0] >> a[1];

    cout << a[0]-1 << " " << a[1] << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

difference of stamina

if we only have 1 left we hold

otherwise it odens'tm atter

0 x
x 0

1 x
x 1



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?