// https://codeforces.com/contest/1358/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
const int maxn = 200500;

int d[maxn*2];

int trng(int n) {
    return (n*(n+1))/2;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        d[i] = a;
        d[n+i] = a;
    }

    int l = 1;
    int r = 0;
    int days = 0, hugs = 0;
    int ans = 0;
    while(r < 2*n) {
        r++;

        days += d[r];
        hugs += trng(d[r]);

        while(days > x) {
            if(days - d[l] < x) break;

            days -= d[l];
            hugs -= trng(d[l]);
            l++;
        }

        int diff = max(0LL, trng(days-x));

        ans = max(ans, hugs-diff);
    }

    cout << ans << endl;
}
