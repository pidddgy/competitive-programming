// https://atcoder.jp/contests/abc170/tasks/abc170_c

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int X, N;
    cin >> X >> N;

    set<int> p;
    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        p.emplace(a);
    }

    pii ans = {INT_MAX, INT_MAX};
    for(int i = -1e5; i <= 1e5; i++) {
        pii x = pii(abs(X-i), i);

        if(!p.count(i)) {
            ans = min(ans, x);
        }
    }

    cout << ans.se << endl;
}
