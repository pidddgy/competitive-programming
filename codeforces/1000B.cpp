// https://codeforces.com/contest/1000/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, M;
    cin >> n >> M;

    vector<int> a;

    for(int i = 0; i < n; i++) {
        int _;
        cin >> _;

        a.emplace_back(_);
    }

    a.insert(a.begin(), 0);
    a.push_back(M);

    int f[2][a.size()];
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < a.size(); j++) {
            f[i][j] = 0;
        }
    }

    for(int i = a.size()-2; i >= 0; i--) {
        f[0][i] = f[1][i+1];
        f[1][i] = (a[i+1]-a[i]) + f[0][i+1];
    }

    int ans = f[1][0];
    for(int i = 0; i+1 < a.size(); i++) {
        if(a[i+1]-a[i] < 2) continue;

        int tp = (i%2==1)^1;
        int sum = f[1][0] - f[tp][i];
        ans = max(ans, sum+(a[i+1]-a[i]-1) + f[tp][i+1]);
    }

    cout << ans << endl;
}