// https://codeforces.com/contest/1419/problem/C

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

const int maxn = (int)1e3+50;

int a[maxn];

void solve() {
    int n, x;
    cin >> n >> x;

    int xcnt = 0;
    int osum = 0;
    int sum = 0;
    int ocnt = 0;
    for(int i = 1; i <= n; i++) {
       cin >> a[i]; 
       sum += a[i];

       if(a[i] != x) {
           osum += a[i];
           ocnt++;
       } else if(a[i] == x) {
           xcnt++;
       }
    }

    if(ocnt == 0) {
        cout << 0 << endl;
        return;
    }

    // the cases where we have 1 is when one of them is infected and we can make them all the same
    for(int i = 1; i <= xcnt; i++) {
        int r = x*i;
        r += osum;

        int shit = i+ocnt;
        r %= shit;

        if(r == 0) {
            cout << 1 << endl;
            return;
        }
    }

    // otherwise, check if we can make them all equal to x
    sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += a[i];
    }
 
    if(sum == x*n) {
        cout << 1 << endl;
        return;
    }
   
    // we can always have 2 by infecting one then we can put the other ones all to x
    cout << 2 << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*
1
4 68
68 70 69  68

1
3 69
0 0 0

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?