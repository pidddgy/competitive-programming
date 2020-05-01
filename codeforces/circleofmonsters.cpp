// https://codeforces.com/contest/1334/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int N;
        cin >> N;

        pii a[N+1];
        for(int i = 1; i <= N; i++) {
            cin >> a[i].fi >> a[i].se;
        }

        int sum = 0;
        int b[N+1];
        for(int i = 2; i <= N; i++) {
            b[i] = max(0LL, a[i].fi - a[i-1].se);
            sum += b[i];
        }

        b[1] = max(0LL, a[1].fi - a[N].se);
        sum += b[1];

        int ans = LLONG_MAX;
        for(int i = 1; i <= N; i++) {
            int cost = sum + a[i].fi - b[i];
            ans = min(ans, cost);
        }
        cout << ans << endl;
    }
}