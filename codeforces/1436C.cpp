// https://codeforces.com/contest/1436/problem/C

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

const int maxn = 1005;
const int MOD = (int)1e9+7;

int mod(int num) {
    return num%MOD;
}

int n, x, pos;
int b[maxn];
int fac[maxn];

int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return mod(t*t % MOD * a%MOD);
    return mod(t*t % MOD);
}

int modinv(int a) {
    return modpow(a, MOD-2);
}

int choose(int pool, int k) {
    if(k > pool) return 0;
    return mod(mod(fac[pool]*modinv(fac[pool-k])));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fac[0] = 1;
    for(int i = 1; i <= 1002; i++) {
        fac[i] = mod(mod(mod(fac[i-1]*i)));
    }

    cin >> n >> x >> pos;    

    vector<int> a;
    int ree = 0;
    for(int i = 1; i <= pos; i++) {
        a.push_back(-300);
        ree++;
    }
    a.push_back(x);
    ree++;

    while(ree < n) {
        a.push_back(LLONG_MAX);
        ree++;
    }

    int left = 0, right = sz(a);

    while(left < right) {
        int mid = (left+right)/2;
        if(a[mid] <= x) {
            left = mid+1;
            b[mid] = -1;
        } else {
            right = mid;
            b[mid] = 1;
        }
    }

    int lo = 0, hi = 0, cute = 0;
    for(int i = 0; i < n; i++) {
        // fixed, dont have choice
        if(i == pos) continue;

        if(b[i] == -1) {
            lo++;
        } else if(b[i] == 1) {
            hi++;
        } else {
            cute++;
        }
    }

    int t1 = mod(mod(choose(x-1, lo)));
    int t2 = mod(mod(choose(n-x, hi)));
    int t3 = mod(mod(mod(fac[cute])));

    cout << mod(mod(mod(mod((t1*t2))*t3))) << endl;
}

/*

simulate a binary search, find all indices that have to be too high
if we need x bigger numbers

use a sorted array to find correct values

x! * rem!

-1 must be lower
1 must be higher
0 doesn't matter
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
