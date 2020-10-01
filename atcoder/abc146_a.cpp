// https://atcoder.jp/contests/abc146/tasks/abc146_a

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

    map<string, int> ans = {
        {"SUN", 7},
        {"MON", 6},
        {"TUE", 5},
        {"WED", 4},
        {"THU", 3},
        {"FRI", 2},
        {"SAT", 1},
    };

    string S;
    cin >> S;

    cout << ans[S] << endl;
}
