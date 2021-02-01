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
        if(s[i] == 'W') a[i]++;
        else if(s[i] == 'A') b[i]++;
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
        if(s[i] == 'W' or s[i] == 'C') continue;

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


for each A how many W will it have
get pre, tot

if it is first occurence there are pre W
if second occurence there are pre+tot W
if third pre+2*tot W

for each A how many C will it have?
suf, tot

if it is first occurence then suf+(k-1)*tot
if second occurence then suf + (k-2)*tot

i = 1
p * (s + (k-1)*t)

i = 2
p+t * (s + (k-2)*t)

i = 3
(p+2*t) * (s + (k-3)*t)

i = 3
(p+3*t) * (s + (k-4)*t)

combine like terms blobsweats
(p * (s + (k-1)*t)) + ((p+t) * (s + (k-2)*t)) + (p+2*t) * (s + (k-3)*t) + (p+3*t) * (s + (k-4)*t)

ab + cd

start = 3, add = 5
3, 8, 13, 18, 23, 28

start = 4, add = 3
19, 16, 13, 10, 7, 4

the only things changing are p and s


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
