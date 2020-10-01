// https://codeforces.com/contest/812/problem/B

using namespace std;
#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr

const int maxn = 150;

int a[maxn][maxn];

// 0 = left, 1 = right
int dp[2][maxn];
int cnt[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for(int j = 0; j < s.size(); j++) {
            a[i][j+1] = s[j]-'0';
            if(s[j] == '1') cnt[i]++;
        }
    }

    int st = -1;

    for(int i = n; i >= 1; i--) {
        if(cnt[i]) st = i;
    }

    if(st == -1) {
        cout << 0 << endl;
        return 0;
    }

    for(int i = st; i <= n; i++) {
        dp[0][i] = dp[1][i] = INT_MAX-100;

        if(cnt[i] == 0) {
            dp[0][i] = dp[0][i-1] + (i != st);
            dp[1][i] = dp[1][i-1] + (i != st);
            continue;
        }
        // from left
        int cur1 = 0;
        for(int j = 2; j <= m+2-1; j++) {
            if(a[i][j] == 1) {
                cur1++;
            }
            if(cur1 == cnt[i]) {
                dp[0][i] = min(dp[0][i-1]+(((j-1)*2)+1), dp[1][i-1]+m+2);
                if(i == st) dp[0][i] = j-1;
                break;
            }
        }

        cur1 = 0;
        int step = 0;
        for(int j = m+2-1; j >= 2; j--) {
            step++;
            if(a[i][j] == 1) {
                cur1++;
            }

            if(cur1 == cnt[i]) {
                dp[1][i] = min(dp[1][i-1]+(step*2)+1, dp[0][i-1]+m+2);
                if(i == st) dp[1][i] = step;
                break;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cerr << dp[0][i] << " " << dp[1][i] << endl;
    }


    cout << dp[0][n] << endl;
}