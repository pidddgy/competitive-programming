// https://codeforces.com/contest/992/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int MOD = 1000000007;

int mod(int a, int b=MOD) {
    return ((a%b)+b)%b;
}

int modmul(int a, int b) {
    return (a%MOD) * (b%MOD) % MOD;
}
int modpow(int a, int exp){
    if(exp == 0) return 1;
    int t = modpow(a,exp/2);
    if(exp%2) return t*t%MOD*a%MOD;
    return t*t%MOD;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x, k;
    cin >> x >> k;

    if(x == 0) {
        cout << 0 << endl;
        return 0;
    }

    int ans = modmul(x, modpow(2, k+1)) - modpow(2, k)+1;
    ans = mod(ans);

    cout << ans << endl;
}