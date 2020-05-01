// https://codeforces.com/contest/1342/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        string t;
        cin >> t;

        if(count(t.begin(), t.end(), '1') == 0 or count(t.begin(), t.end(), '0') == 0) {
            cout << t << endl;
        }  else {
            for(int i = 0; i < t.size(); i++) {
                cout << "01";
            }
            cout << endl;
        }
    }
}