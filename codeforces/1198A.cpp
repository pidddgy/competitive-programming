// https://codeforces.com/contest/1198/problem/A

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, I;
    cin >> n >> I;

    int l = 1;
    int r = n;
    int u = -1;

    while(l <= r) {
        int m = (l+r)/2;

        int k = ceil(log2(m));
        int bits = n*k;

        if(bits <= I*8) {
            l = m+1;
            u = m;
        } else {
            r = m-1;
        }
    }

    cerr << "at most " << u << " unique elements" << endl;

    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        cnt[a]++;
    }
    int sz = cnt.size();

    vector<pii> cnts;
    cnts.emplace_back(pii(-1, -1));
    for(pii x: cnt) {
        cnts.emplace_back(x);
    }

    int psa[sz+5];
    for(int i = 0; i < sz+5; i++) psa[i] = 0;

    for(int i = 1; i <= sz; i++) {
        psa[i] = psa[i-1]+cnts[i].se;
        cerr << psa[i] << " ";
    }
    cerr << endl;

    int ans = n;
    for(int i = 1; i <= sz; i++) {
        int rb = min(sz, i+u-1);

        ans = min(ans, n-(psa[rb]-psa[i-1]));
    }

    cout << ans << endl;
}