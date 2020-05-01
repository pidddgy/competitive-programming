// https://codeforces.com/contest/689/problem/E

#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define fi first
#define se second
#define cerr if(false) cerr
#define ll long long
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;

const int MOD = 1e9 + 7;
ll fpow(ll  b, ll exp, ll mod = MOD){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

ll modinv(ll a) {
    return fpow(a, MOD-2);
}

ll fac[2*100500];

ll nk(int n, int k) {
    if(n < k) return 0;
    return (fac[n] * (modinv(fac[k])*modinv(fac[n-k]) % MOD)) % MOD;
}

int main() {
    fac[0] = 1;
    fac[1] = 1;
    for(int i = 2; i < 2*100500; i++) {
        fac[i] = fac[i-1]*i;
        fac[i] %= MOD;
    }

    ll n, k;
    cin >> n >> k;

    vector<pii> events;
    unordered_map<int, int> eventsm;
    ll ma = 0;
    for(ll i = 1; i <= n; i++) {
        ll l, r;
        cin >> l >> r;
        ma = max(ma, r);
        eventsm[l]++;
        eventsm[r+1]--;
    }


    for(pii x: eventsm) {
        events.emplace_back(x);
    }

    events.emplace_back(ma+1, 0);

    sort(events.begin(), events.end());

    ll ans = 0;
    ll cur = 0;
    for(int i = 0; i < events.size(); i++) {
        pii x = events[i];
        cerr << "on " << i << endl;
        cerr << x.fi << "," << x.se << endl;
        cerr << "cur is " << cur << endl;
        watch(k)
        if(i > 0) {
            watch(nk(cur, k))
            ans += nk(cur, k) * abs(events[i].fi-events[i-1].fi);
            ans %= MOD;

            cerr << "ans is now " << ans << endl;
        }
        cerr << endl;
        cur += x.se;
    }

    cout << ans << endl;

}