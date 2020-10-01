// https://atcoder.jp/contests/abc104/tasks/abc104_d

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

const int maxn = 100500;
const int MOD = (int)1e9+7;

int a[maxn], b[maxn], c[maxn], q[maxn];
int totq = 0;

int pows[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    pows[0] = 1;
    for(int i = 1; i < maxn; i++) {
        pows[i] = (pows[i-1]*3) % MOD;
    }

    string s;
    cin >> s;

    int n = s.size();

    s = "."+s;

    for(int i = 1; i <= n; i++) {
        if(s[i] == 'A') a[i]++;
        else if(s[i] == 'B') b[i]++;
        else if(s[i] == 'C') c[i]++;
        else q[i]++;
    }    

    for(int i = 1; i <= n; i++) {
        a[i] += a[i-1];
        b[i] += b[i-1];
        c[i] += c[i-1];
        q[i] += q[i-1];
    }

    totq = q[n];

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'A' or s[i] == 'C') continue;

        int rem = 0;
        if(s[i] == '?') rem = 1;

        int ab = a[i-1];
        int qb = q[i-1];

        int ca = c[n]-c[i];
        int qa = q[n]-q[i];

        // ABC ?BC AB? ?B?
        ans += (((ab * ca) % MOD) * (pows[totq-rem])) % MOD;
        ans %= MOD;

        ans += (((qb * ca) % MOD) * (pows[totq-rem-1])) % MOD;
        ans %= MOD;

        ans += (((ab * qa) % MOD) * (pows[totq-rem-1])) % MOD;
        ans %= MOD;

        ans += (((qb * qa) % MOD) * (pows[totq-rem-2])) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
