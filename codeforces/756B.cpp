// https://codeforces.com/contest/756/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 100500;

int a[maxn], dp[maxn];
int n;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int j = 1, k = 1;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        dp[i] = dp[i-1]+20;
        while(j <= i and a[j]+90 <= a[i]) {
            j++;
        }

        dp[i] = min(dp[i], dp[j-1]+50);

        while(k <= i and a[k]+1440 <= a[i]) {
            k++;
        }

        dp[i] = min(dp[i], dp[k-1]+120);

        cout << dp[i]-dp[i-1] << endl;
    }
}
