// https://codeforces.com/contest/449/problem/A

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

int n, m, k;

int f(int r, int c) {
    return (n/(r+1LL))*(m/(c+1LL));
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    if(k > n+m-2) {
        cout << -1 << endl;
        return 0;
    }

    if(n > m) swap(n, m);

    int ans = 0;

    if(k <= n-1) {
        // cerr << "hi" << endl;
        ans = max(ans, f(0, k));
        ans = max(ans, f(k, 0));
    } else if (n <= (k+1) and (k+1) <= m) {
        ans = f(0, k);
    } else {
        ans = f(k-(m-1), m-1);
    }
    
    cout << ans << endl;
}
