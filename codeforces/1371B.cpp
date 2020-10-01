// https://codeforces.com/contest/1371/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ll long long

ll trng(ll n) {
    return (n*(n+1))/2;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        ll n, r;
        cin >> n >> r;

        ll ans = 0;

        if(r >= n) {
            ans = trng(n-1)+1;
        } else {
            ans = trng(r);
        }

        cout << ans << endl;
    }    
}
