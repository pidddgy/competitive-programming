// https://codeforces.com/contest/1330/problem/C

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define fi first
#define se second
#define endl '\n'
#define unfilled -300000

int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> ans;
    int ma = 0;
    for(int i = 1; i <= m; i++) {
        int _;
        cin >> _;

        int p = n-_+1;

        ans.emplace_back(p);
        ma = max(ma, p+_-1);
    }

    if(ma == n) {
        for(int x: ans) {
            cout << x << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

}