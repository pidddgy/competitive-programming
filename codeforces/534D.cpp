// https://codeforces.com/contest/534/problem/D

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 200500;
int n;
set<pii> S[3];
int ans[maxn];

void no() {
    cout << "Impossible" << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        S[x%3].emplace(x, i);
    }

    int cur = 0;

    for(int i = 1; i <= n; i++) {
        auto it = S[cur%3].lower_bound(pii(cur, INT_MIN));

        pii next;
        if((it != S[cur%3].end()) and (*it).fi == cur) {
            next = *it;
            S[cur%3].erase(it);
        } else {
            if(it == S[cur%3].begin()) {
                no();
            } else {
                it = prev(it);
                next = *it;
                S[cur%3].erase(it);
            }
        }

        cur = next.fi+1;
        ans[i] = next.se;
    }

    cout << "Possible" << endl;
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
