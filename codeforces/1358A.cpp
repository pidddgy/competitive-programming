// https://codeforces.com/contest/1358/problem/0

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;

        int prod = n*m;

        cout << (prod+1)/2 << endl;
    }
}
