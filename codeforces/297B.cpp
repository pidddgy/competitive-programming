// https://codeforces.com/contest/297/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define pii pair<int, int>
#define fi first
#define se second

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    map<int, int> cnta;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        cnta[x]++;
    }

    map<int, int> cntb;
    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;

        cntb[x]++;
    }

    vector<pii> cntsa;
    vector<pii> cntsb;

    for(pii x: cnta) {
        cntsa.emplace_back(x);
        cerr << x.fi << " " << x.se << endl;
    }
    cerr << endl;

    for(pii x: cntb) {
        cntsb.emplace_back(x);
        cerr << x.fi << " " << x.se << endl;
    }
    cerr << endl;

    int pos = cntb.size()-1;
    int as = 0, bs = 0;
    for(int i = cntsa.size()-1; i >= 0; i--) {
        as += cntsa[i].se;

        while(cntsb[pos].fi >= cntsa[i].fi and pos >= 0) {
            bs += cntsb[pos].se;
            pos--;
        }
        cerr << cntsa[i].fi << endl;
        cerr << as << " " << bs << endl;
        cerr << endl;
        if(as>bs) {
            cout << "YES" << endl;
            cerr << "on" << cntsa[i].fi << endl;
            watch(as)
            watch(bs)
            return 0;
        }
    }

    cout << "NO" << endl;
}