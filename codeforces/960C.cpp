// https://codeforces.com/contest/960/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int X, d;
    cin >> X >> d;

    vector<int> ans;
    int cur = 1;
    for(int i = 1; i <= 60; i++) {
        if(X & (1LL << (i-1))) {
            for(int j = 1; j <= i-1; j++) {
                ans.emplace_back(cur);
            }
            cur += d+1;
            ans.emplace_back(cur);
            cur += d+1;
        }
    }   
    
    cout << ans.size() << endl;
    for(int x: ans) {
        cout << x << " ";
    }
    cout << endl;
}
