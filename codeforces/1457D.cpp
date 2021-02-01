// https://codeforces.com/contest/1457/problem/D

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

const int maxn = 100500;

int n;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    a[0] = LLONG_MIN;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    a[n+1] = LLONG_MAX;

    int ans = -1;

    // try 2
    for(int i = 1; i <= n-3; i++) {
        int l = a[i-1];
        int m = a[i]^a[i+1];
        int r = a[i+2]^a[i+3];
        int r2 = a[i+4];

        if(!(l <= m and m <= r and r <= r2)) {
            cerr << "2 on " << i << endl;
            ans = 2;
        }
    }

    // try 1
    for(int i = 1; i <= n-1; i++) {
        int l = a[i-1];
        int m = a[i]^a[i+1];
        int r = a[i+2];

        if(!(l <= m and m <= r)) {
            cerr << "1 on " << i << endl;
            ans = 1;
        }
    }

    cout << ans << endl;   
}

/*

guess: always 2 moves

we want to create exactly one split point

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?