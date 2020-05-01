// https://codeforces.com/contest/569/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define ld long double

    ld T, S, q;
    cin >> T >> S >> q;

    int ans = 0;
    while(S < T) {
        S *= q;
        ans++;
    }

    cout << ans << endl;
}