// https://atcoder.jp/contests/abc146/tasks/abc146_c

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

    int a, b, x;
    cin >> a >> b >> x;

    int l = 1, r = 1e9;

    int lgood = 0;
    while(l <= r) {
        int m = (l+r)/2;

        int cost = a*m + b*to_string(m).size();

        if(cost <= x) {
            lgood = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    cout << lgood << endl;
}
