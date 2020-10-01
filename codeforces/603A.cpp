// https://codeforces.com/contest/603/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

int f(string s, int st) {
    int res = 0;
    int look = st;
    for(int i = 0; i < s.size(); i++) {
        if(s[i]-'0' == look) {
            res++;
            look ^= 1;
        }
    }

    // watch(res)
    return res;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = min(n, max(f(s, 1), f(s, 0))+2);
    cout << ans << endl;
}