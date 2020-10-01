// https://atcoder.jp/contests/abc142/tasks/abc142_b

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int h;
        cin >> h;

        ans += (h >= K);
    }

    cout << ans << endl;
}
