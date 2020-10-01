// https://atcoder.jp/contests/arc064/tasks/arc064_b

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int ans = s.size()%2;

    if(s[0] == s.back()) {
        ans ^= 1;
    }

    if(ans) cout << "First" << endl;
    else cout << "Second" << endl;
}
