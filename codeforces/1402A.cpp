// https://codeforces.com/contest/1402/problem/A

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

const int maxn = 100500;
const int MOD = 1e9+7;
const int inv2 = 500000004; //2^-1 mod 10^9+7
int h[maxn], w[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    n++;

    vector<pii> S;
    S.emplace_back(0, 0);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int wlen = 0;

        while(S.back().fi > h[i]) {
            int hprev = max(h[i], S[sz(S)-2].fi);
            int hdiff = S.back().fi-hprev;
            wlen = (wlen + S.back().se)%MOD;

            watch(hprev)
            watch(hdiff)
            S.pop_back();

            int a = (((((hdiff*(hdiff+1)%MOD) * inv2)%MOD) + ((hdiff*hprev)%MOD))%MOD)%MOD;
            int b = (((wlen*(wlen+1))%MOD)*inv2)%MOD;

            ans += (a*b)%MOD;
            ans %= MOD;
        }

        if(S.back().fi == h[i]) {
            S.back().se = (S.back().se+wlen+w[i])%MOD;
        } else {
            S.emplace_back(h[i], ((wlen+w[i])%MOD));
        }
    }

    cout << (ans+MOD)%MOD << endl;
}

/*

use subtask 5 sol to calculate for increasing sections

only calculate increasing sections w/ stack

push 0, 0 to both ends

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
