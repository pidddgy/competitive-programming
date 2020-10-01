// https://codeforces.com/contest/567/problem/C

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int a[n+1];
    map<int, int> cntl;
    map<int, int> cntr;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cntr[a[i]]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        cntr[a[i]]--;
        if(a[i]%k == 0)
            ans += cntl[a[i]/k] * cntr[a[i]*k];
        cntl[a[i]]++;
    }

    cout << ans << endl;
}