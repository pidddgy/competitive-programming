// https://codeforces.com/contest/626/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= INT_MAX; i++) {
        if(n <= i/2) {
            if(m <= i/3) {
                if(n+m <= (i/2 + i/3) - i/6) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
}