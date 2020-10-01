// https://codeforces.com/contest/1420/problem/D

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

const int maxn = 300500;

int l[maxn], r[maxn];
vector<int> cmp;

int add[3*maxn];
int sub[3*maxn];

const int MOD = 998244353;

int fac[3*maxn];
int md(int num) {
    return (num+MOD)%MOD;
}

int modmul(int a, int b) {
    return md(a*b);
}

int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return md(t*t % MOD * a%MOD);
    return md(t*t % MOD);
}

int modinv(int a) {
    return md(modpow(a, MOD-2));
}

int choose(int n, int k) {
    if(n == k) return 1;
    if(k > n) return 0;
    return md(modmul(fac[n], modinv(modmul(fac[k], fac[n-k]))));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    fac[0] = 1LL;
    for(int i = 1; i < 3*maxn; i++) {
        fac[i] = md(fac[i-1]*i);
    }

    // watch(choose(2, 24))

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        cmp.emplace_back(l[i]);
        cmp.emplace_back(r[i]);
    }

    sort(all(cmp));
    cmp.erase(unique(all(cmp)), cmp.end());
    for(int i = 1; i <= n; i++) {
        l[i] = lower_bound(all(cmp), l[i]) - cmp.begin()+1;
        r[i] = lower_bound(all(cmp), r[i]) - cmp.begin()+1;

        add[l[i]]++;
        sub[r[i]]++;
    }

    int cur = 0;
    int ans = 0;
    for(int i = 1; i <= maxn*2; i++) {
        for(int j = 1; j <= add[i]; j++) {
            ans += md(choose(cur, k-1));
            ans = md(md(ans));
            cur++;
        }

        cur -= sub[i];
        assert(cur >= 0);
    }

    cout << md(md(ans)) << endl;
}

/*

line sweep kinda thing

when we push a new element in, we only consider ways that include this element

so maintain current number of lights on
when pushing:
    add cur choose k-1
    update cur

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
