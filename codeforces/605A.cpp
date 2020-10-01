// https://codeforces.com/contest/605/problem/A

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
const int maxn = 100500;

int dp[maxn];
int n, lis;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        dp[a] = dp[a-1]+1;
        lis = max(lis, dp[a]);
    }

    cout << n-lis << endl;
}
