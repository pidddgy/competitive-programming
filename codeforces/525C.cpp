// https://codeforces.com/contest/525/problem/C 

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 100500;
int a[maxn];
map<int, int> cnt;
vector<pii> cnts;
vector<pii> ncnts;

int sq(int n) {
    return n*n;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for(pii x: cnt) {
        cnts.emplace_back(x);
    }
    sort(cnts.begin(), cnts.end(), greater<pii>());

    for(int i = 0; i+1 < cnts.size(); i++) {
        cerr << cnts[i].fi << "," << cnts[i+1].fi << endl;
        if(cnts[i].se&1 and (cnts[i+1].fi == cnts[i].fi-1)) {
            cnts[i].se--;
            cnts[i+1].se++;
        }
        
        if(cnts[i].se&1) cnts[i].se--;
    }
    cerr << "----" << endl;
    for(pii x: cnts) {
        if(x.se != 0) {
            cerr << x.fi << "," << x.se << endl;
            ncnts.emplace_back(x);
        }
    }

    int ans = 0;
    for(int i = 0; i < ncnts.size(); i++) {
        while(ncnts[i].se >= 4) {
            ans += sq(ncnts[i].fi);
            ncnts[i].se -= 4;
        }

        if(i+1 < ncnts.size()) {
            if(ncnts[i].se >= 2 and ncnts[i+1].se >= 2) {
                ans += ncnts[i].fi * ncnts[i+1].fi;

                ncnts[i].se -= 2;
                ncnts[i+1].se -= 2;
            }
        }
    }

    cout << ans << endl;
}
