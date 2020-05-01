// https://codeforces.com/contest/1335/problem/0

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int bound = (n/2)+1;

        int ans = n-1-bound+1;

        cout << ans << endl;
    }
}