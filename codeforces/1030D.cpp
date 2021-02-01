// https://codeforces.com/contest/1030/problem/D

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int cpy = k;

    if((2*n*m) % k) {
        cout << "NO" << endl;
        return 0;
    }

    if(k % 2 == 0) {
        k /= 2;
    }

    int g = gcd(n, k);
    int a = n/g;
    k /= g;

    g = gcd(m, k);
    int b = m/g;
    k /= g;

    if(cpy % 2) {
        if(a < n) a *= 2;
        else b *= 2;
    }

    cout << "YES" << endl;
    cout << "0 0" << endl;
    cout << 0 << " " << b << endl;
    cout << a << " " << 0 << endl;
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
