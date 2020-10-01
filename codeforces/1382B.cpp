// https://codeforces.com/contest/1382/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

const int maxn = 100500;
int dp[maxn];
int a[maxn];
void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[n] = true;
    for(int i = n-1; i >= 1; i--) {
        if(a[i] == 1) {
            dp[i] = !dp[i+1];
        } else {
            dp[i] = true;
        }
    }

    if(dp[1]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    for(int i = 1; i <= n; i++) {
        dp[i] = false;
        a[i] = 0;
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}