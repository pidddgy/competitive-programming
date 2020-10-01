// https://codeforces.com/contest/1353/problem/0

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;

        if(n == 1) {
            cout << 0 << endl;
        } else if(n == 2) {
            cout << m << endl;
        } else {
            cout << m*2 << endl;
        }
    }
}