// https://codeforces.com/contest/822/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define pii pair<int, int>
#define fi first
#define se second

const int maxr = 200500;

struct voucher {
    int l, r, cost;

    voucher(int ll, int rr, int ccost) {
        l = ll;
        r = rr;
        cost = ccost;
    }
};

bool comp(voucher &le, voucher &ri) {
    if(le.l != ri.l) {
        return le.l < ri.l;
    } else return le.r < le.r;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    int mi[maxr];
    for(int i = 0; i < maxr; i++) {
        mi[i] = INT_MAX;
    }
    
    vector<pii> upd[maxr];
    vector<voucher> arr;
    for(int i = 1; i <= n; i++) {
        int l, r, cost;
        cin >> l >> r >> cost;
        
        arr.emplace_back(l, r, cost);

        upd[r].emplace_back(l, cost);
    }   

    sort(arr.begin(), arr.end(), comp);
    int pos = 0;
    map<int, int> seen;
    int ans = INT_MAX;
    for(int i = 1; i < maxr; i++) {
        while(pos < arr.size() and arr[pos].l == i) {
            int need = x - (arr[pos].r - arr[pos].l + 1);
            if(seen.find(need) != seen.end()) {
                ans = min(ans, arr[pos].cost + seen[need]);
            }
            pos++;
        }
        // break;

        for(pii u: upd[i]) {
            if(seen.find(i-u.fi+1) == seen.end()) {
                seen[i-u.fi+1] = u.se;
            } else {
                seen[i-u.fi+1] = min(seen[i-u.fi+1], u.se);
            }
        }
    }

    // for(pii p: seen) {
    //     cerr << p.fi << " " << p.se << endl;
    // }

    if(ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}