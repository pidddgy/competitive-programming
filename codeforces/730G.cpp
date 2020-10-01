// https://codeforces.com/contest/730/problem/G

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

vector<pii> all;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    all.emplace_back(0, 0);
    all.emplace_back(LLONG_MAX, LLONG_MAX);

    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        int s, d;
        cin >> s >> d;

        int l = s, r = (s+d)-1;
        // cerr << "would add " << l << " " << r << endl;
        bool ok = true;
        for(int i = 0; i < all.size(); i++) {
            // cerr << "checking " << all[i].fi << "," << all[i].se << endl;
            if(all[i].fi <= r and all[i].se >= l) {
                ok = false;
            }
        }

        if(ok) {
            cout << l << " " << r << endl;
            all.emplace_back(l, r);
            sort(all.begin(), all.end());
            continue;
        } else {
            for(int i = 0; i < all.size()-1; i++) {
                if(all[i+1].fi-all[i].se-1 >= d) {
                    cout << all[i].se+1 << " " << all[i].se+d << endl;
                    all.emplace_back(all[i].se+1, all[i].se+d);
                    sort(all.begin(), all.end());
                    break;
                }
            }
        }


    }
}