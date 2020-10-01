// https://codeforces.com/contest/416/problem/C
#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second

struct req {
    int cnt, pay, ind;

    req(int cntt, int payy, int indd) {
        cnt = cntt;
        pay = payy;
        ind = indd;
    }
};

bool comp(req &l, req &r) {
    return l.pay > r.pay;    
}

set<pii> tables;
vector<req> reqs;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int c, p;
        cin >> c >> p;

        reqs.emplace_back(c, p, i);
    }
    sort(reqs.begin(), reqs.end(), comp);

    int k;
    cin >> k;

    for(int i = 1; i <= k; i++) {
        int r;
        cin >> r;

        tables.emplace(r, i);
    }

    vector<pii> ans;
    int sum = 0;
    for(req x: reqs) {
        cerr << "searching for " << x.cnt << " " << INT_MIN << endl;
        if(tables.lower_bound(pii(x.cnt, INT_MIN)) != tables.end()) {
            auto ptr = tables.lower_bound(pii(x.cnt, INT_MIN));
            ans.emplace_back(pii(x.ind, (*ptr).se));
            sum += x.pay;
            tables.erase(ptr);
        }
    }
    
    cout << ans.size() << " " << sum << endl;
    for(pii x: ans) {
        cout << x.fi << " " << x.se << endl;
    }
}
