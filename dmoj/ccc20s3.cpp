// https://dmoj.ca/problem/ccc20s3

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
#define aint(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 200500;
const int SEED = 199;
const int SEED2 = 131;
const int MOD = (int)1e9+7;
int seedpow[maxn];
int seedpow2[maxn];
int hsh[maxn];
int hsh2[maxn];

int modpow(int a, int exp) {
    if(exp == 0) return 1;

    int t = modpow(a, exp / 2);
    if(exp % 2) return t*t % MOD * a%MOD;
    return t*t % MOD;
}

int modinv(int a) {
    return modpow(a, MOD-2);
}

int gethash(int l, int r) {
    return ((((hsh[r] - hsh[l-1]) * modinv(seedpow[l])) % MOD)+MOD)%MOD;
}

int gethash2(int l, int r) {
    return ((((hsh2[r] - hsh2[l-1]) * modinv(seedpow2[l])) % MOD)+MOD)%MOD;
}

int ncnt[26];

int psa[26][200500];
map<int, map<int, bool>> seen;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    seedpow[0] = 1;
    seedpow2[0] = 1;
    for(int i = 1; i <= 200300; i++) {
        seedpow[i] = seedpow[i-1]*SEED;
        seedpow[i] %= MOD;

        seedpow2[i] = seedpow2[i-1]*SEED2;
        seedpow2[i] %= MOD;
    }

    string N, H;
    cin >> N >> H;

    int nsz = sz(N);
    int hsz = sz(H);

    N = "."+N;
    H = "."+H;

    for(int i = 1; i <= nsz; i++) {
        ncnt[N[i]-'a']++;
    }

    for(int i = 1; i <= hsz; i++) {
        hsh[i] = hsh[i-1] + ((H[i] * seedpow[i]) % MOD);
        hsh[i] %= MOD;

        hsh2[i] = hsh2[i-1] + ((H[i] * seedpow2[i]) % MOD);
        hsh2[i] %= MOD;
    }

    for(int i = 1; i <= hsz; i++) {
        psa[H[i]-'a'][i]++;
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 1; j <= hsz; j++) {
            psa[i][j] += psa[i][j-1];
        }
    }

    int ans = 0;
    for(int i = 1; i+nsz-1 <= hsz; i++) {
        bool ok = true;
        for(int j = 0; j < 26; j++) {
            if(psa[j][i+nsz-1] - psa[j][i-1] != ncnt[j]) ok = false;
        }

        if(ok) {
            if(!seen[gethash(i, i+nsz-1)][gethash2(i, i+nsz-1)]) {
                ans++;
                seen[gethash(i, i+nsz-1)][gethash2(i, i+nsz-1)] = true;
            }
        }
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
