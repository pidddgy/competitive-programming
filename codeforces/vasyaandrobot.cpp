// https://codeforces.com/contest/354/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    cout << fixed << setprecision(50) << pow(0.5, 80) << endl;
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'

    int n, l, r, ql, qr;
    cin >> n >> l >> r >> ql >> qr;

    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[0] = 0;

    int psa[n+1];
    psa[0] = 0;
    for(int i = 1; i <= n; i++) {
        psa[i] = a[i];
        psa[i] += psa[i-1];
    }

    int ans = INT_MAX;
    for(int i = 0; i <= n; i++) {
        int tl = i;
        int tr = n-i;

        int cl = psa[i] * l;
        int cr = (psa[n] - psa[i]) * r;
        int pen;
        if(tl > tr) {
            pen = max(0LL, (tl-tr)-1)*ql;
        } else {
            pen = max(0LL, (tr-tl)-1)*qr;
        }

        ans = min(ans, cl + cr + pen);
    }

    cout << ans << endl;
}