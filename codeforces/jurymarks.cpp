// https://codeforces.com/contest/831/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int k, n;
    cin >> k >> n;

    int a[k+1];
    for(int i = 1; i <= k; i++) {
        cin >> a[i];
    } 

    int b[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int psa[k+1];
    psa[0] = 0;
    for(int i = 1; i <= k; i++) {
        psa[i] = psa[i-1]+a[i];
    }

    int ans = 0;
    unordered_map<int, bool> used;
    for(int i = 1; i <= k; i++) {
        int cur = b[1] - psa[i];
        if(used[cur])  {
            cerr << "breaking " << cur << endl;
            continue;
        } else {
            used[cur] = true;
        }
        cerr << "i is " << i << endl;
        watch(cur)
        unordered_map<int, bool> seen;
        for(int j = 1; j <= k; j++) {
            cur += a[j];
            seen[cur] = true;
        }

        bool good = true;
        for(int i = 1; i <= n; i++) {
            if(!seen[b[i]]) {
                good = false;
            }
        }

        if(good) cerr << "using " << b[1]-psa[i] << endl;

        ans += good;
    }

    cout << ans << endl;
}