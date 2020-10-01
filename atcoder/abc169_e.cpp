// https://atcoder.jp/contests/abc169/tasks/abc169_e

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 200500;

int a[maxn], b[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
    }

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    int x, y;
    if(n&1) {
        x = a[n/2+1];
        y = b[n/2+1];
    } else {
        x = a[n/2] + a[n/2+1];
        y = b[n/2] + b[n/2+1];
    }

    cout << y-x+1 << endl;
}
