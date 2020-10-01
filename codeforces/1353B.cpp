// https://codeforces.com/contest/1353/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        int a[n+1], b[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for(int i = 1; i <= n; i++) {
            cin >> b[i];
        }

        sort(a+1, a+n+1);
        sort(b+1, b+n+1, greater<int>());

        for(int i = 1; i <= k; i++) {
            if(b[i] > a[i]) {
                swap(a[i], b[i]);
            }
        }

        int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += a[i];
        }

        cout << sum << endl;
    }
}