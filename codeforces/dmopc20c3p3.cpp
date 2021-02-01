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
#define sz(a) (int)(a).size()
#define y1 lsdjkfhshfdsighoihweogihewoghi
#define all(x) (x).begin(), (x).end()

int mod = (int)1e9+7;

int md(int num) {
    return (num+mod)%mod;
}

int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return md(md(t*t) * a);
    return md(t*t);
}

int modinv(int a) {
    return modpow(a, mod-2);
}

int geosum(int a, int r, int n) {
    return md(md(a*(md((1-modpow(r, n))*modinv(1-r)))));
}


void solve() {
    int n, m, k, b;
    cin >> n >> m >> k >> b;

    if(k == 2 and n % 2 == 0 and m % 2 == 0) {
        // assert(false);
        // n has to be divisible by 2
        // do every other
        int ans = 0;
        int seed = 1;
        int shit = m/2;

        // for(int i = 1; i <= n; i++) {
        //     if(i % 2 == 0) {
        //         ans += ((shit)*seed)%mod;
        //         ans %= mod;
        //     }

        //     seed *= b;
        //     seed %= mod;
        // }
        ans = md(shit*geosum(b, md(b*b), n/2));
        cout << ans << endl;
        return;
    } else if(k == 1 and n%3 == 0) {
        // assert(false);
        // must be divisible by 3
        int ans = 0;
        int seed = 1;
        int shit = m;

        // for(int i = 1; i <= n; i++) {
        //     if((i) % 3 == 0) {
        //         ans += ((shit)*seed)%mod;
        //         ans %= mod;
        //     }

        //     seed *= b;
        //     seed %= mod;
        // }

        ans = md(shit*geosum(modpow(b, 2), modpow(b, 3), n/3));
        cout << ans << endl;
        return;
    }

    // how much shit poured into each
    int l = 1, r = 1e9;
    int shit = -1;
    while(l <= r) {
        int mid = (l+r)/2;

        int x = k*mid + 2*mid;

        if(x < m) {
            l = mid+1;
        } else if(x > m) {
            r = mid-1;
        } else {
            shit = mid;
            break;
        }
    }

    if(shit == -1) {
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    // int seed = 1;
    // for(int i = 1; i <= n; i++) {
    //     ans += ((shit)*seed)%mod;
    //     ans %= mod;

    //     seed *= b;
    //     seed %= mod;
    // }
    ans = geosum(shit, b, n);

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while(q--) {
        solve();
    }
}

/*

guess: m has to be divisible by k+2 (sample)

each bucket gets poured k+2 times

if k == 2 or 2 do every other

 
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
