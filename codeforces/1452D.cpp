// https://codeforces.com/contest/1452/problem/D

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


const int MOD = 998244353;

int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return t*t % MOD * a%MOD;
    return t*t % MOD;
}

int modinv(int a) {
    return modpow(a, MOD-2);
}

int mod(int hugs) {
    return (hugs+MOD)%MOD;
}

const int maxn = 200500;
int fib[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fib[0] = 0;
    fib[1] = 1;

    for(int i = 2; i <= 2e5; i++) {
        fib[i] = fib[i-1]+fib[i-2];
        fib[i] %= MOD;
    }

    int n;
    cin >> n;

    int tot = modpow(2, n);
    cout << mod(fib[n]*(modinv(tot))) << endl;
}

/*

count cases, actually a combo problem

leftmost must take all the way to end and so on

gfg says its fibonacci uhh



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
