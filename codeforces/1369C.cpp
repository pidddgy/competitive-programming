// https://codeforces.com/contest/1369/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 200500;

int a[maxn], w[maxn];
set<int> S[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for(int i = 1; i <= k; i++) {
            cin >> w[i];
        }


        sort(a+1, a+n+1, greater<int>());

        sort(w+1, w+k+1);

        int ind = 1;

        for(int i = 1; i <= k; i++) {
            S[i].emplace(a[ind]);
            ind++;
        }

        for(int i = 1; i <= k; i++) {
            for(int j = 1; j <= w[i]-1; j++) {
                S[i].emplace(a[ind]);
                // cerr << "emplacing " << a[ind] << endl;
                ind++;
            }
        }

        int ans = 0;
        for(int i = 1; i <= k; i++) {
            // for(int x: S[i]) {
            //     cerr << x << " ";
            // }
            // cerr << endl;
            ans += *S[i].begin() + *S[i].rbegin();
        }

        cout << ans << endl;

        for(int i = 1; i <= n; i++) {
            a[i] = 0;
        }

        for(int i = 1; i <= k; i++) {
            w[i] = 0;
            S[i].clear();
        }
    }
}
