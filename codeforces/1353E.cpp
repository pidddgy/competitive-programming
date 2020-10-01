// https://codeforces.com/contest/1353/problem/E

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int maxn = 1000500; 
string s;
int psa[maxn];
int dp[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        cin >> s;

        s = "."+s;

        for(int i = 1; i <= n; i++) {
            psa[i] = psa[i-1]+(s[i]=='1');
        }


        int ans = INT_MAX;
        for(int i = 1; i <= n; i++) {
            if(i < k) {
                dp[i] = psa[i-1];
            } else {
                dp[i] = dp[i-k]+(psa[i-1]-psa[i-k]);
            }

            if(s[i] != '1') dp[i]++;
            dp[i] = min(dp[i], psa[i-1]);

        }

        for(int i = 1; i <= n; i++) {
            ans = min(ans, dp[i]+(psa[n]-psa[i]));
        }
        cout << ans << endl;

        for(int i = 0; i <= n; i++) {
            psa[i] = 0;
            dp[i] = 0;
        }
        s.clear();
    }
}