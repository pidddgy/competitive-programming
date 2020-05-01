// https://codeforces.com/contest/1343/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    #define int long long
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        map<int, int> cnt;
        for(int i = 1; i <= n/2; i++) {
            cnt[a[i]+a[n-i+1]]++;
        }

        int pref[(2*k) + 500];
        for(int i = 0; i < (2*k)+500; i++) {
            pref[i] = 0;
        }

        for(int i = 1; i <= n/2; i++) {
            int l = min(a[i], a[n-i+1])+1;
            int r = max(a[i], a[n-i+1])+k;

            pref[l]++;
            pref[r+1]--;
        }

        for(int i = 1; i <= 2*k; i++) {
            pref[i] += pref[i-1];
        }

        int ans = INT_MAX;
        for(int i = 2; i <= 2*k; i++) {
            ans = min(ans, (pref[i]-cnt[i]) + ((n/2)-pref[i])*2);
        }

        cout << ans << endl;
    }
}