// http://m1.codeforces.com/contest/1328/problem/B

#include <bits/stdc++.h>
#define int long long
using namespace std;

// smallest trng >= n
int f(int n) {
    int l = 1;
    int r = n;

    int lastgood = -1;
    while(l <= r) {
        int m = (l+r)/2;

        // cout << "m is " << m << endl;

        int trng = (m*(m+1)) / 2;
        // cout << "trng is " << trng << endl;
        if(trng >= n) {
            r = m-1;
            lastgood = m;
        } else {
            l = m+1;
        }
    }

    return lastgood;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'
    // cout << f(5) << endl;
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        string s = "";
        for(int i = 1; i <= n; i++) {
            s += "a";
        }

        int trng = f(k);
        int val = (trng*(trng+1)/2);

        s[n-trng-1] = 'b';
        s[n-trng+abs(val-k)] = 'b';

        // cout << trng << endl;

        cout << s << endl;
    }
}