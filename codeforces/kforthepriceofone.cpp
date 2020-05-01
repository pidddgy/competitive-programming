// https://codeforces.com/contest/1282/problem/B2

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define cerr if(false) cerr
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 200500;

int a[maxn];
int dp[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {


        int n, p, k;
        cin >> n >> p >> k;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        sort(a+1, a+n+1);

        for(int i = 1; i <= n; i++) {
            dp[i] = min(i-k >= 0 ? dp[i-k] : INT_MAX, dp[i-1]) + a[i];
        }
        for(int i = 1; i <= n; i++) {
            cerr << a[i] << " ";
        }
        cerr << endl;
        for(int i = 1; i <= n; i++) {
            cerr << dp[i] << " ";
        }
        cerr << endl;
        for(int i = n; i >= 0; i--) {
            if(dp[i] <= p) {
                cout << i << endl;
                for(int i = 0; i < n; i++) {
                    a[i] = 0;
                    dp[i] = 0;
                }
                break;
            }
        }
    }

}