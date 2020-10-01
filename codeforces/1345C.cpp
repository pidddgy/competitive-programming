// https://codeforces.com/contest/1345/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long

int mod(int a, int b) {
    return ((a%b)+b)%b;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    // cout << -1337 % 3 << endl;
    // watch(mod(-1337, 3))
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        set<int> S;
        for(int i = 0; i < n; i++) {
            S.emplace(mod(a[mod(i, n)]+i, n));
        } 

        if(S.size()== n) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
