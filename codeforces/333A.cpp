// https://codeforces.com/contest/333/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define ll long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    for(ll i = 1;; i *= 3) {
        if(n%i) {
            cout << n/i+1LL << endl;
            break;
        }
    }    
}