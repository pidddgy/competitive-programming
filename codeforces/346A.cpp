// https://codeforces.com/contest/346/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int g = a[1];
    int ma = a[1];
    for(int i = 2; i <= n; i++) {
        g = gcd(g, a[i]);
        ma = max(ma, a[i]);
    }

    if((n-(ma/g))%2) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }
}
