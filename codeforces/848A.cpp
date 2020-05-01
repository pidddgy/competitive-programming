// https://codeforces.com/contest/848/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define ll long long

ll trng(ll n) {
    return (n*(n+1))/2;
}
signed main() {

    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll k;
    cin >> k;

    if(k == 0) {
        cout << "a" << endl;
        return 0;
    }
    
    ll rem = k;

    string ans = "";
    char cur = 'a';
    for(ll i = 10000; i >= 2; i--) {
        while(trng(i-1) <= rem) {
            cerr << "using " << i << endl;
            watch(trng(i-1))
            rem -= trng(i-1);
            for(ll j = 1; j <= i; j++) {
                ans.push_back(cur);
            }
            cur++;
        }
    }

    cout << ans << endl;
}