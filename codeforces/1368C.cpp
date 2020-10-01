// https://codeforces.com/contest/1368/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const vector<pii> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int r = 2;
    int c = 2;

    set<pii> ans;

    ans.emplace(r-1, c-1);
    for(int i = 1; i <= n; i++) {
        for(pii d: dir) {
            ans.emplace(r+d.fi, c+d.se);
        }
        ans.emplace(r, c);
        r++;
        c++;
    }
    ans.emplace(r, c);


    cout << ans.size() << endl;
    for(auto c: ans) {
        cout << c.fi << " " << c.se << endl;
    }
}
