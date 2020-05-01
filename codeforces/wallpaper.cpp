// https://codeforces.com/blog/entry/3462

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 600;

int a[maxn];
int dp[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        for(int i = 0; i < maxn; i++) {
            a[i] = 0;
            dp[i] = 0;
        }

        int n, p, k;
        cin >> n, p, k;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        sort(a+1, a+n+1);

        for(int i = 1; i <= n; i++) {
            dp[i] = min(dp[i-k], dp[i-1]) + a[i];
        }

        for(int i = n; i >= 0; i--) {
            if(dp[i] <= p) {
                cout << i << endl;
                break;
            }
        }
    }

}