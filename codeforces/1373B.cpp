// https://codeforces.com/contest/1373/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int zc = 0, oc = 0;

        for(char x: s) {
            if(x == '0') {
                zc++;
            } else {
                oc++;
            }
        }

        if(min(zc, oc) & 1) {
            cout << "DA" << endl;
        } else {
            cout << "NET" << endl;
        }
    }
}
