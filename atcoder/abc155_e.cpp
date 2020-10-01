// https://atcoder.jp/contests/abc155/tasks/abc155_e

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int maxl = 1000500;
const int INF = LLONG_MAX-500;

int pre[2];
int dp[2];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    reverse(s.begin(), s.end());
    s += "0";

    pre[1] = INF;

    for(int i = 0; i < s.size(); i++) {
        int need = s[i]-'0';
        dp[0] = min(pre[0]+need, pre[1]+need+1);
        dp[1] = min(pre[0]+(10-need), pre[1]+(9-need));

        for(int i = 0; i <= 1; i++) {
            pre[i] = dp[i];
        }
    }

    cout << dp[0] << endl;
}
