// https://codeforces.com/contest/337/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
#define cerr if(false) cerr
const int MOD = 1000000009;

int mod(int a, int b) {
    return ((a%b)+b)%b;
}

int modpow(int a, int exp){
    if(exp == 0) return 1;
    int t = modpow(a,exp/2);
    if(exp%2) return t*t%MOD*a%MOD;
    return t*t%MOD;
}

int geosum(int a, int r, int n) {
    if(r==1) return n;
    if(n==1) return a*2;
    return (a * ((modpow(r, n)-1) * modpow(r-1, MOD-2) % MOD)) % MOD;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int inc = n-m;
    watch(inc)

    int l = 0;
    int r = 1000000000;
    int lgood = -1;
    int remain = -1;

    // find min doubles needed
    while(l <= r) {
        int mid = (l+r)/2;
        watch(l)
        watch(r)
        watch(mid)

        int amt = mid*k;
        int rem = n-amt;
        watch(rem)
        if(rem/k <= inc) {
            r = mid-1;
            lgood = mid;
            remain = rem;
        } else {
            l = mid+1;
        }
        cerr << endl;
    }

    cerr << "we need to double " << lgood << " times" << endl;
    watch(remain)
    watch(geosum(k, 2, lgood+1)-k)
    watch(geosum(3, 2, 3)-k)

    int ans = max(0LL, remain-inc);

    if(lgood) {
        ans += geosum(k, 2, lgood+1)-k;
    }
    // cout << (geosum(k, 2, lgood+1)-k + max(0LL, remain-inc)) % MOD << endl;
    cout << mod(ans, MOD) << endl;
}