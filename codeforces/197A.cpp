// https://codeforces.com/contest/197/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr

bool dp[10005];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b, r;
    cin >> a >> b >> r;

    if(r*2 <= min(a, b)) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
}