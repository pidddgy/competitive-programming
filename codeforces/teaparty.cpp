// https://codeforces.com/contest/808/problem/C

#include <bits/stdc++.h>
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
int main() {
    int n, w;
    cin >> n >> w;

    pii a[n+1];
    int A[n+1];
    for(int i = 1; i <= n; i++) {
        int _;
        cin >> _;

        A[i] = _;
        a[i] = make_pair(_, i);
    }

    sort(a+1, a+n+1, greater<pii>());

    int ans[n+1];
    for(int i = 1; i <= n; i++) ans[i] = 0;

    for(int i = 1; i <= n; i++) {
        ans[i] = (A[i]+1) / 2;
        w -= ans[i];
    }

    if(w < 0) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        pii x = a[i];
        int temp = min(A[x.se]-ans[x.se], w);
        ans[x.se] += min(A[x.se]-ans[x.se], w);
        w -= temp;
    }

    if(w > 0) {
        cout << -1 << endl;
        cerr << w << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;


}