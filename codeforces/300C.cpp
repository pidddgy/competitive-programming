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


const int MOD = 1e9+7;
int fac[(int)2e6];

int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return t*t % MOD * a%MOD;
    return t*t % MOD;
}

int modinv(int a) {
    return modpow(a, MOD-2);
}

int nk(int n, int k) {
    if(n < k) return 0;
    return (fac[n] * (modinv(fac[k])*modinv(fac[n-k]) % MOD)) % MOD;
}

int a, b, n;
bool good(int num) {
    string s = to_string(num);
    for(char x: s) {
        int val = x-'0';
        if(val != a and val != b) return false;
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    fac[0] = 1;
    fac[1] = 1;
    for(int i = 2; i <= 1e6+5; i++) {
        fac[i] = (fac[i-1]*i)%MOD;
    }

    cin >> a >> b >> n;

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        if(good(i*a + b*(n-i))) {
            cerr << "choosing " << i << " a is good" << endl;
            watch(n)
            watch(nk(n, i))
            ans += nk(n, i);
            ans %= MOD;
        }
    }

    cout << ans << endl;
}

/*

there are n+1 possible sums

if a sum is good then it is n choose k 

for each sum
    how many ways are there to reach this sum using only a and b?

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
