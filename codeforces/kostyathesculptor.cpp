// https://codeforces.com/contest/733/problem/D

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int ma = 0;
    int maind = 0;
    int maind2 = 0;
    
    unordered_map<int, unordered_map<int, pii>> m;
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        vector<int> x = {a, b, c};

        sort(x.begin(), x.end());

        pii add = max({m[x[1]][x[2]], m[x[2]][x[1]]});
        watch(add.fi)
        if(min({x[0]+add.fi, x[1], x[2]}) > ma) {
            maind = i;
            maind2 = add.se;
            ma = min({x[0]+add.fi, x[1], x[2]});
        }

        cerr << endl;
        m[a][b] = max(m[a][b], pii(c, i));
        m[b][a] = max(m[b][a], pii(c, i));

        m[a][c] = max(m[a][c], pii(b, i));
        m[c][a] = max(m[c][a], pii(b, i));

        m[b][c] = max(m[b][c], pii(a, i));
        m[c][b] = max(m[c][b], pii(a, i));
    }



    vector<int> ans;
    ans.emplace_back(maind);
    if(maind2) ans.emplace_back(maind2);

    cout << ans.size() << endl;
    for(int x: ans) cout << x << " ";
    cout << endl;
}