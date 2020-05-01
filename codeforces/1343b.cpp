// https://codeforces.com/contest/1343/problem/B

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

        if((n/2)%2 != 0) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        int esum = 0;
        for(int i = 1; i <= n/2; i++) {
            cout << 2*i << " ";
            esum += 2*i;
        }

        int osum = 0;
        for(int i = 1; i <= (n/2)-1; i++) {
            cout << (2*i)-1 << " ";
            osum += (2*i)-1;
        }

        cout << esum - osum << endl;
    }
}