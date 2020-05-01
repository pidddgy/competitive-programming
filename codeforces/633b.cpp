// https://codeforces.com/contest/1339/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        sort(a+1, a+n+1);


        if(n % 2 == 0) {
            int st = (n)/2;

            int right = 1;
            for(int i = st; i >= 1; i--) {
                // cout << i << " " << i+right << endl;
                cout << a[i] << " " << a[i+right] << " ";
                right += 2;
            }

            cout << endl;
        } else {
            int st = (n+1)/2;

            cout << a[st] << " ";

            st--;
            int right = 2;

            for(int i = st; i >= 1; i--) {
                cout << a[i] << " " << a[i+right] << " ";
                right += 2;
            }

            cout << endl;
        }

    }
}