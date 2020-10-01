// https://codeforces.com/contest/322/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    for(int i = 0; i <= 15; i++) {
        int loc = 0;
        int mix = min(min({a, b, c}), i);

        loc = mix;

        for(int x: multiset<int>({a, b, c})) {
            loc += (x-mix)/3;
        }

        ans = max(ans, loc);
    }

    cout << ans << endl;
}
