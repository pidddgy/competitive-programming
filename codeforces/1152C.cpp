// https://codeforces.com/contest/1152/problem/C

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


int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

set<int> fac(int n) {
    set<int> S;
    for(int i = 1; i*i <= n; i++) {
        if(n%i==0) {
            S.emplace(i);
            S.emplace(n/i);
        }
    }
    return S;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if(a > b) swap(a, b);

    int mi = LLONG_MAX;
    int ans = 0;
    for(int q: fac(b-a)) {
        watch(q)
        int k = (q-(a%q))%q;

        watch(k)
        int l = lcm(a+k, b+k);

        watch(l)
        if(l < mi) {
            mi = l;
            ans = k;
        }
    }

    cout << ans << endl;
}

/*

(a+k)*(b*k) / gcd(a+k, b+k)

apply euclidean algorithm once, gcd(a, b) = gcd(b-a, a)

gcd(a+k, b+k) -> gcd(b-a, a+k)

q must be divisor of b-a

look for minimum k so that a+k is divisible by q
don't worry about b+k because a mod q = b mod q
    -> if q is divisor of b-a then a mod q = b mod q

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
