// https://codeforces.com/contest/1166/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n+1];

    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        a[i] = abs(a[i]);
    }


    sort(a+1, a+n+1);

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int l = i+1;
        int r = n;
        int lastgood = -1;
        while(l <= r) {
            int m =(l+r)/2;

            if(abs(a[i]-a[m]) <= min(a[i], a[m])) {
                lastgood = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }

        cerr << i << " lastgood is " << lastgood << endl;
        if(lastgood != -1)
        ans += lastgood-i;
    }

    cout << ans << endl;
}