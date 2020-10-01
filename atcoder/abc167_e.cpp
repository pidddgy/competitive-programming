// https://atcoder.jp/contests/abc167/tasks/abc167_e

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define aint(x) (x).begin(), (x).end()

const int MOD =  998244353;
int fac[2000500];

int modmul(int a, int b) {
    return (a*b) % MOD;
}

int modpow(int a, int exp) {
    if(exp == 0) return 1int;

    int t = modpow(a, exp / 2);
    if(exp % 2) return t*t % MOD * a%MOD;
    return t*t % MOD;
}

int modinv(int n) {
    return modpow(n, MOD-2);
}

int choose(int n, int k) {
    return modmul(fac[n], modinv(modmul(fac[k], fac[n-k])));
}



signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    fac[0] = 1;
    for(ll i = 1; i <= 2000000; i++) {
        fac[i] = modmul(fac[i-1], i);
    }

    for(int i = 0; i <= K; i++) {
        int ree = 
    }
}