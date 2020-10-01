// https://codeforces.com/problemset/problem/869/C

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

const int maxn = 5050;
const int MOD = 998244353;

int a, b, c;
int fac[maxn];
int choose[maxn][maxn];

int f(int x, int y) {
    int ret = 0;
    for(int k = 0; k <= min(x, y); k++) {
        int add = fac[k];

        add *= choose[x][k];
        add %= MOD;

        add *= choose[y][k];
        add %= MOD;

        ret += add;
        ret %= MOD;
    }

    return ret;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    fac[0] = choose[0][0] = 1;

    for(int i = 1; i <= 5000; i++) {
        fac[i] = fac[i-1]*i;
        fac[i] %= MOD;
    }

    for(int i = 1; i <= 5000; i++) {
        choose[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
            choose[i][j] %= MOD;
        }
    }

    cin >> a >> b >> c;

    int ans = 1;
    ans *= f(a, b);
    ans %= MOD;
    ans *= f(a, c);
    ans %= MOD;
    ans *= f(b, c);
    ans %= MOD;

    cout << ans << endl;
}

/*

you can have any edges from the 3 groups

choose nodes to connect from group a, choose nodes to connect from group b, pick what order to connect
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
