// https://codeforces.com/contest/715/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        if(i == 1) {
            cout << 2 << endl;
        } else {
            cout << ((i*(i+1)) * (i+1)) - (i-1)<< endl;
        }
    }
}