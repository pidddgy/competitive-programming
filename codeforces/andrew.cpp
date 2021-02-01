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

const int MOD = 1e9+7;
int mod(int num) {
    return num;
    // return (num+MOD)%MOD;
}

const int maxn = 1e6+500;

int fac[maxn];

    int n, d;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d;

    fac[1] = 1;
    for(int i = 2; i <= 1e6; i++) {
         fac[i] = (fac[i-1]*i)%MOD;
    }

    watch(fac[1])

    int shit = mod(mod((n-d+1)*(n-1)) * fac[n-2]);
    watch(shit)
}

/*

there are n-d pairs

put n-d pairs in n-1 positions

fac[n-2]

how to account for overcounted pairs?




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
