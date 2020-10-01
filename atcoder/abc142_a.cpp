// https://atcoder.jp/contests/abc142/tasks/abc142_a

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    long double N;
    cin >> N;

    int odd = (N+1)/2;

    // watch(odd)
    long double ans = odd/N;

    cout << fixed << setprecision(10) << ans << endl;
}
