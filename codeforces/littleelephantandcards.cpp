// https://codeforces.com/contest/204/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define int long long
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, int> fcnt;
    unordered_map<int, int> bcnt;
    set<int> all;
    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        all.emplace(a);
        all.emplace(b);

        if(a == b) fcnt[a]++;
        else {
            fcnt[a]++;
            bcnt[b]++;
        }
    }

    int mi = INT_MAX;
    for(int x: all) {
        // watch(x)
        int need = (n+1)/2;

        if(fcnt[x] + bcnt[x] >= need) {
            // watch(fcnt[x])
            // watch(bcnt[x])
            // watch(need)
            // cerr << "will use " << max(0, need-fcnt[x]) << endl;
            mi = min(mi, max(0LL, need-fcnt[x]));
        }
    }
    
    if(mi == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << mi << endl;
    }

}