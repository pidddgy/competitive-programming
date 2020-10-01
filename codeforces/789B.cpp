// https://codeforces.com/contest/789/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

map<int, int> bad;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int b, q, l, m;
    cin >> b >> q >> l >> m;

    for(int i = 1; i <= m; i++) {
        int a;
        cin >> a;

        bad[a] = true;
    }

    int ans = 0;

    int its = 0;
    while(abs(b) <= abs(l) and its < 1e6) {
        if(!bad[b]) {
            ans++;
        }
        b *= q;
        its++;
    }

    if(its == 1e6 and !set<int>({0, 1}).count(ans)) {
        cout << "inf" << endl;
    } else {
        cout << ans << endl;
    }
}
