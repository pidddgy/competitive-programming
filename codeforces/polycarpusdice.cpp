// https://codeforces.com/problemset/problem/534/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define cerr if(false) cerr
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, A;
    cin >> n >> A;

    int d[n+1];
    int tot = 0;
    for(int i = 1; i <= n; i++) {
        cin >> d[i];
        tot += d[i];
    }

    for(int i = 1; i <= n; i++) {
        int lb = max(1LL, A-(tot-d[i]));
        int ub = min((A-(n-1)), d[i]);

        watch(lb)
        watch(ub)
        watch(((ub-lb)+1))
        cout << d[i] - ((ub-lb)+1) << " ";
    }
    cout << endl;
}