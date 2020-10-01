// https://codeforces.com/contest/1370/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

const int maxn = 1005;

int a[2*maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 1; i <= 2*n; i++) {
            cin >> a[i];
        }

        vector<int> odds;
        vector<int> evens;

        for(int i = 1; i <= 2*n; i++) {
            if(a[i]&1) {
                evens.emplace_back(i);
            } else {
                odds.emplace_back(i);
            }
        }

        // for(int x: evens) {
        //     cerr << x << " ";
        // }

        // cerr << endl;
        // for(int x: odds) {
        //     cerr << x << " ";
        // }
        // cerr << endl;
        int discard = 2;

        if(odds.size()&1) {
            odds.pop_back();
            discard--;
        }
        if(evens.size()&1) {
            evens.pop_back();
            discard--;
        }

        // if both are even that means we can pick any, if one of them is odd the other must be odd

        while(odds.size() and discard) {
            odds.pop_back();
            discard--;
        }

        while(evens.size() and discard) {
            evens.pop_back();
            discard--;
        }

        while(odds.size() >= 2) {
            cout << odds.back() << " ";
            odds.pop_back();
            cout << odds.back() << endl;
            odds.pop_back();
        }

        while(evens.size() >= 2) {
            cout << evens.back() << " ";
            evens.pop_back();
            cout << evens.back() << endl;
            evens.pop_back();
        }

        

        for(int i = 1; i <= 2*n; i++) {
            a[i] = 0;
        }
    }
}
