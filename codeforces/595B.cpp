// https://codeforces.com/contest/595/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define cerr if(false) cerr

const int MOD = 1000000007;

int ans = 1;
int upb;

int fpow(int a, int exp){
    if(exp == 0) return 1;
    int t = fpow(a,exp/2);
    if(exp%2) return t*t*a;
    return t*t;
}


int cnt(int x, int y) {
    watch(x)
    watch(y)
    int tot = (upb)/x+1;
    int lo = ((upb+1)/10)*y;
    int hi = (((upb+1)/10)*(y+1))-1;

    int lov = lo/x;
    if(lo%x) lov++;

    int hiv = hi/x;

    // watch(lo)
    // watch(hi)

    return tot-(hiv-lov+1);
}

map<int, int> a;
map<int, int> b;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    upb = fpow(10, k)-1;

    for(int i = 1; i <= n/k; i++) {
        int _;
        cin >> _;

        a[i] = _;
    }

     for(int i = 1; i <= n/k; i++) {
        int _;
        cin >> _;

        b[i] = _;
    }

    for(int i = 1; i <= n/k; i++) {
        ans *= cnt(a[i], b[i]) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;


}