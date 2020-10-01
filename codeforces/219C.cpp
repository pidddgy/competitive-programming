// https://codeforces.com/problemset/problem/219/C

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = 500500;

int dp[maxn][50];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        for(int j = 0; j < 50; j++) {
            dp[i][j] = INT_MAX-500;
        }
    }

    int N, K;
    cin >> N >> K;

    string s;
    cin >> s;

    s = "."+s;

    for(int i = 0; i < 26; i++) {
        if(s[N]-'A' == i) dp[N][i] = 0;
        else dp[N][i] = 1;
    }

    for(int i = N-1; i >= 1; i--) {
        for(int j = 0; j < K; j++) {
            for(int k = 0; k < K; k++) {
                if(j == k) continue;

                dp[i][j] = min(dp[i][j], dp[i+1][k] + ((s[i]-'A') != j));
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 26; j++) {
            cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }

    int ans = INT_MAX;
    for(int i = 0; i <= 26; i++) {
        ans = min(ans, dp[1][i]);
    }

    cout << ans << endl;

    int last = -1;

    for(int i = 1; i <= N; i++) {
        int mi = INT_MAX;
        for(int j = 0; j < K; j++) {
            if(last == j) continue;

            mi = min(mi, dp[i][j]);
        }

        for(int j = 0; j <= K; j++) {
            if(last == j) continue;

            if(dp[i][j] == mi) {
                cout << (char)(j+'A');
                last = j;
                break;
            }
        }
    }

    cout << endl;
}

/*
338 000 000
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
