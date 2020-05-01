// https://codeforces.com/contest/1009/problem/D

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if(m < n-1) {
        cout << "Impossible" << endl;
        return 0;
    }

    vector<pii> ans;
    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            if(gcd(i, j) == 1) {
                ans.emplace_back(i, j);
                if(ans.size()==m) break;
            }
        }
        if(ans.size()==m) break;
    }

    if(ans.size() != m) {
        cout << "Impossible" << endl;
    } else {
        cout << "Possible" << endl;
        for(pii x: ans) {
            cout << x.fi << " " << x.se << endl;
        }
    }

}