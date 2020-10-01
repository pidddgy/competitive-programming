// https://codeforces.com/contest/792/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

using ll = long long;

int f(ll n) {
    for(int i = 1;; i++) {
        if((1LL << i) == n) return i-1;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;
    
    // max bit allowed
    int ma = f(n+1);

    while(q--) {
        ll u;
        string s;

        cin >> u >> s;

        for(char x: s) {
            // U -> clear lsb, set bit to left of lsb
            // L -> clear lsb, set bit to right of lsb
            // R -> set bit to right of lsb
            int lsb = '?';

            for(int i = 0;; i++) {
                if((1LL << i) & u) {
                    lsb = i;
                    break;
                }
            }

            if(x == 'U') {
                if(lsb == ma) continue;

                u &= ~(1LL << lsb);
                u |= (1LL << (lsb+1));
            } else if(x == 'L') {
                if(lsb == 0) continue;

                u &= ~(1LL << lsb);
                u |= (1LL << (lsb-1));
            } else if(x == 'R') {
                if(lsb == 0) continue;

                u |= (1LL << (lsb-1));
            }
        }

        cout << u << endl;
    }
}
