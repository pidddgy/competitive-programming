// https://codeforces.com/contest/453/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define ld long double
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    ld m, n;
    cin >> m >> n;

    ld tot = 0;

    for(ld i = 1; i <= m; i++) {
        ld add = i*(pow((i/m), n) - pow((i-1)/m, n));
        tot += add;
    }

    cout << fixed << setprecision(20) << tot << endl;
}