// https://atcoder.jp/contests/abc142/tasks/abc142_e

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxm = 1500;

int N, M;
vector<int> c[maxm];
int a[maxm];

int dp[5000];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= M; i++) {
        int b;
        cin >> a[i] >> b;

        for(int j = 1; j <= b; j++) {
            int x;
            cin >> x;

            c[i].emplace_back(x);
        }
    }

    for(int i = 1; i < 5000; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for(int i = 0; i <= (1<<N)-1; i++) {
        for(int j = 1; j <= M; j++) {
            int state = i;
            for(int x: c[j]) {
                state |= (1<<(x-1));
            }            

            dp[state] = min(dp[state], dp[i] + a[j]);
        }
    }

    if(dp[(1<<N)-1] == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[(1<<N)-1] << endl;
    }
}
