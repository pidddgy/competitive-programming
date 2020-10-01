// https://codeforces.com/contest/540/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;

    int a[k+1];

    int sum = 0;
    for(int i = 1; i <= k; i++) {
        cin >> a[i];
        sum += a[i];
    }

    vector<int> ans;
    sort(a+1, a+k+1);

    int geqt = 0;
    for(int i = 1; i <= k; i++) {
        if(a[i] >= y) {
            geqt++;
        }
    }

    while(geqt < (n+1)/2) {
        ans.emplace_back(y);
        geqt++;
    }

    while(ans.size() < n-k) {
        ans.emplace_back(1);
    }

    for(int el: ans) {
        sum += el;
    }

    if(sum > x or ans.size() > n-k) {
        cout << -1 << endl;
    } else {
        for(int el: ans) {
            cout << el << " ";
        }
        cout << endl;
    }
}
