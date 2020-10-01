// https://atcoder.jp/contests/abc167/tasks/abc167_a

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long
#define all(x) (x).begin(), (x).end()

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    string ans = "Yes";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != t[i]) {
            ans = "No";
        }
    }

    cout << ans << endl;
}
