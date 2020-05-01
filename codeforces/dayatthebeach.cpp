// https://codeforces.com/contest/599/problem/C 

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n+1];
    multiset<int> S;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        S.emplace(a[i]);
    }

    int ma = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ma = max(ma, a[i]);
        S.erase(S.find(a[i]));
        cerr << "on " << i << endl;
        if(S.empty()) {
            ans++;
            cerr << "empty" << endl;
        } else if(*S.begin() >= ma) {
            cerr << "greater" << endl;
            ans++;
        }
        cerr << endl;
    }

    cout << ans << endl;

}