// https://codeforces.com/contest/524/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int maxn = 5500;

map<int, int> mi;
int a[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        for(int j = 1; j <= 20; j++) {
            mi[a[i]*j] = j;
        }
    }    

    int q;
    cin >> q;

    while(q--) {
        int x;
        cin >> x;

        int ans = INT_MAX;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= 20; j++) {
                int rem = x-a[i]*j;

                if(mi.count(rem) and j+mi[rem] <= k) {
                    ans = min(ans, j+mi[rem]);
                }
            }
        }

        if(ans == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
}
