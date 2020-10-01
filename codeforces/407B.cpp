// https://codeforces.com/contest/407/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

const int maxn = 1500;
const int MOD = 1000000007;

int p[maxn];
int dp[maxn];

int mod(int a, int b) {
    return ((a%b)+b)%b;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    for(int i = 1; i <= n; i++) {
        int s1 = dp[i];
        int s2 = 2;
        int s3 = dp[i]-dp[p[i]];

        dp[i+1] = (s1%MOD + s2%MOD + s3%MOD)%MOD;
    }


    cout << mod(dp[n+1], MOD) << endl;
}