// https://codeforces.com/contest/1369/problem/0

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
#define ld long double

const ld ep = 1e-9;
bool isint(ld x) {
    return abs(x - round(x) < ep);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cerr << fixed << setprecision(10);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        if(n % 4 == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}