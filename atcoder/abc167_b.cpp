// https://atcoder.jp/contests/abc167/tasks/abc167_b

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

    int a, b, c, k;
    cin >> a >> b >> c >> k;

    int ans = 0;

    int take = min(a, k);
    a -= take;
    k -= take;
    ans += take;

    take = min(b, k);
    b -= take;
    k -= take;

    take = min(c, k);
    c -= take;
    ans -= take;

    cout << ans << endl;
}
