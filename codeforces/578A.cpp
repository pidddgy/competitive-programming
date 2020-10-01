// https://codeforces.com/contest/578/problem/A

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define ld long double
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    if(a<b) {
        cout << -1 << endl;
    } else {
        ld x = a-b;
        cout << fixed << setprecision(12) << x/2 << endl;
    }
}
