// https://codeforces.com/contest/722/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
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

    set<int> S;

    int b[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int ans[n+1];
    int cur = 0;
    S.emplace(-200);

    for(int i = n; i >= 1; i--) {
        ans[i] = cur;

        S.emplace(b[i]);
        cerr << "emplacing " << b[i] << endl;
        auto lit = S.lower_bound(b[i]);
        if(lit != S.end()) {
            lit--;
        }

        auto uit = S.upper_bound(b[i]);

        if(*lit == -200) {
            cerr << "no lower" << endl;
        } else {
            cerr << *lit << " " << b[i] << endl;
        }

        if(uit == S.end()) {
            cerr << "no upper" << endl;
        } else {
            cerr << b[i] << " " << *uit << endl;
        }





    }
}