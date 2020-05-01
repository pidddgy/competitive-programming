// https://codeforces.com/contest/922/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    // int n = 5;
    // for(int i = 1; i <= 4; i++) {
    //     cout << n%i << endl;
    // }

    int n, k;
    cin >> n >> k;
    
    set<int> S;
    for(int i = 1; i <= min(k, 1000000LL); i++) {
        if(S.count(n%i)) {
            cout << "No" << endl;
            return 0;
        }
        S.emplace(n%i);
    }

    cout << "Yes" << endl;
}