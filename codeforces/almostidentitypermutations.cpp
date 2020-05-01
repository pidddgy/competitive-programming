// https://codeforces.com/contest/888/problem/D

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define ld long double
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;

int fac[1005];
int subfac[1005];
unordered_map<int, unordered_map<int, int>> memo;

int choose(int n, int k) {
    if(memo[n][k]) return memo[n][k];
    if(k == 0) {
        memo[n][k] = 1;
        return 1;
    }
    if(n == k) {
        memo[n][k] = 1;
        return 1;
    }

    memo[n][k] = choose(n-1, k-1) + choose(n-1, k);
    return memo[n][k];
}

int nk[1005][6];

const ld eu = 2.71828182845904523536;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    fac[1] = 1;
    for(int i = 2; i <= 100; i++) {
        fac[i] = 1LL * fac[i-1] * i;
        watch(fac[i])
    }

    subfac[0] = 1;
    subfac[1] = 0;
    subfac[2] = 1;

    for(int i = 3; i <= 10; i++) {
        subfac[i] = (i-1)*(subfac[i-1]+subfac[i-2]);
    }

    for(int i = 1; i <= 10; i++) {
        cerr << subfac[i] << " ";
    }
    cerr << endl;


    int n, k;
    cin >> n >> k;

    int ans = 0;
    for(int i = 0; i <= k; i++) {
        int combs = subfac[i];
        watch(combs)

        watch(choose(n, i))
        ans += choose(n, i) * combs;
    }

    cout << ans << endl;
}