// https://codeforces.com/contest/888/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for(int i = 2; i <= n-1; i++) {
        if(a[i] > a[i-1] and a[i] > a[i+1]) {
            ans++;
        } else if(a[i] < a[i-1] and a[i] < a[i+1]) {
            ans++;
        }
    }

    cout << ans << endl;
}