// https://codeforces.com/contest/351/problem/A

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

const int maxn = 5005;

int a[maxn];

signed main() {
    cerr << fixed << setprecision(3);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    n *= 2;
    
    int d = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        ld x;
        cin >> x;

        a[i] = ((int)(x*1000.0 + (1e-3)))%1000;

        cerr << a[i] << " ";
        if(a[i]) d++;
        sum += a[i];
    }
    cerr << endl;

    watch(sum)
    int mi = LLONG_MAX;
    for(int i = 0; i <= d; i++) {
        if(i <= n/2 and d-i <= n/2) {
            mi = min(mi, abs(sum- i*1000));
        }
    }

    cout << fixed << setprecision(3) << (ld)(mi/1000.0) << endl;
}

/*

let a = old, b = after operations

start with decimals rounding down

brute force number of decimals to round up

rounding up one decimal decreases a-b by 1


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
