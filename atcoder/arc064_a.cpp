// https://atcoder.jp/contests/arc064/tasks/arc064_a

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define int long long
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, x;
    cin >> N >> x;

    vector<int> a(N+5);
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 1; i <= N; i++) {
        ans += max(0LL, (a[i]+a[i-1])-x);
        a[i] -= max(0LL, (a[i]+a[i-1])-x);
    }

    cout << ans << endl;
}
