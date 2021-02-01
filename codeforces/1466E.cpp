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

const int MOD = (int)1e9+7;

const int maxn = 500500;

int a[maxn];

// powers of 2 mod x
int powers[100];
int modpow[100];
int cnt[100];
void solve() {
    for(int i = 0; i < 70; i++) cnt[i] = 0;

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        // scan(a[i]);

        for(int j = 0; j <= 60; j++) {
            if(powers[j] & a[i]) {
                cnt[j]++;
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int an = 0, o = 0;
        for(int j = 0; j <= 60; j++) {
            int p = powers[j];
            if(a[i]&p) {
                an += cnt[j]*modpow[j];
                o += n*modpow[j];
            } else {
                o += cnt[j]*modpow[j];
            }

            an %= MOD;
            o %= MOD;
        }

        ans += (an*o) % MOD;
        ans %= MOD;;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cur = 1;

    for(int i = 0; i <= 60; i++) {
        powers[i] = cur;
        modpow[i] = cur%MOD;

        cerr << cur << " ";
        cur *= 2;
    }
    cerr << endl;
    int t;
    cin >> t;

    while(t--) solve();
}

/*

let cnt = number of elements that has this bit

for and
    contributes cnt * cnt

for or
    contributes cnt * n

solve ansewr for each bit



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?