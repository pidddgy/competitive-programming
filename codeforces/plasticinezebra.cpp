// https://codeforces.com/contest/1025/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int N = s.size();
    s = s+s+s;

    int ans = 0;

    int curRun = 1;
    for(int i = 1; i < s.size(); i++) {
        if(s[i] != s[i-1]) {
            curRun++;
        } else {
            curRun = 1;
        }

        if(curRun > N) curRun = 1;

        ans = max(ans, curRun);
    }
    cout << ans << endl;
}