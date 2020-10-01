// https://codeforces.com/contest/1279/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

const int maxn = 1e6+10;
const int MOD = 998244353;

vector<int> arr[maxn];
int cnt[maxn];

int mulMod(int a, int b) {
	return a * 1ll * b % MOD;
}

template <class T, class U> T powMod(T base, U pow, T) {
    T x = 1;
    for (; pow > 0; pow >>= 1, base = mulMod(base, base)) if (pow & 1) x = mulMod(x, base);
    return x;
}


int addMod(int a, int b) {
	a += b;
	if (a >'
    
    '= MOD) a -= MOD;
	return a;
}

// Modular Multiplicative Inverse of a in Zp for a prime p
// Time Complexity: O(log p)
// Required: 0 < a < p, p * p does not overflow
template <class T> T mulInvModPrime(T a, T p = MOD) { return powMod(a, p - 2, p); }


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;

        arr[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> arr[i][j];
            cnt[arr[i][j]]++;
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int x: arr[i]) {
            int y = mulMod((int)mulInvModPrime(arr[i].size()), mulInvModPrime(n));
            int z = mulMod(cnt[x], mulInvModPrime(n));

            ans = addMod(ans, mulMod(y, z));
        }
    }

    cout << ans << endl;
}