// https://codeforces.com/contest/305/problem/B

#include <bits/stdc++.h>
#define ld long double
using namespace std;
int main() {

    ld p, q;
    cin >> p >> q;

    int n;
    cin >> n;

    ld a[(int)n+1];
    for(int i = 1; i <= n; i++) {
        cin >> a[(int)i];
    }

    ld ans = a[n];
    for(int i = n-1; i >= 1; i--) {
        ans = 1/ans;
        ans += a[i];
    }

    if(p/q == ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}