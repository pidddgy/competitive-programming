// https://codeforces.com/contest/1366/problem/0

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ll long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int a, b;
        cin >> a >> b;

        if(a > b) swap(a, b);

        if(a*2 <= b) {
            cout << a << endl;
        } else {
            cout << (a+b)/3 << endl;
        }
    }
}
