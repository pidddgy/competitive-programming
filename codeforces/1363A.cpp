// https://codeforces.com/contest/1363/problem/0    

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        int n, x;
        cin >> n >> x;

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] %= 2;
        }

        sort(a+1, a+n+1);
        string ans = "No";
        for(int i = 1; i+x-1 <= n; i++) {
            int sum = 0;
            for(int j = i; j <= i+x-1; j++) {
                sum += a[j];
            }

            if(sum%2 == 1) {
                ans = "Yes";
            }
        }

        cout << ans << endl;
    }
}
