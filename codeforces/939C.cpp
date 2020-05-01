// https://codeforces.com/contest/939/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int psa[2*n];
    psa[0] = a[0];
    for(int i = 1; i < 2*n; i++) {
        psa[i] = psa[i-1]+a[i%n];
    }

    int s, f;
    cin >> s >> f;

    int sz = f-s;
    watch(sz)
    int ma = 0;
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        int sum = psa[i+sz]-psa[i];
        watch(i)
        watch(sum)
        int t = s-(i+1);
        if(t <= 0) t += n;
        watch(t)
        if(sum > ma) {
            ma = sum;
            ans = t;
        }

        if(sum==ma) ans = min(ans, t);
        cerr << endl;
    }

    cout << ans << endl;
}