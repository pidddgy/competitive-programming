// https://codeforces.com/contest/1304/problem/C

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
using namespace std;

struct state {
    // left point, right point
    int time, lp, rp;
    state(int Time, int Lp, int Rp) {
        time = Time;
        lp = Lp;
        rp = Rp;
    }
};

signed main() {
    int q;
    cin >> q;

    while(q--) {
        int n, m;
        cin >> n >> m;

        vector<state> a;
        a.emplace_back(0, m, m);
        for(int i = 1; i <= n; i++) {
            int t, l, h;
            cin >> t >> l >> h;
            a.push_back(state(t, l, h));
        }

        for(state x: a) {
            cerr << x.time << " " << x.lp << " " << x.rp << endl;
        }

        string ans = "YES";
        for(int i = 1; i < a.size(); i++) {
            cerr << "currently on " << i << endl;
            // binary search for first reachable state in a[i].l->r
            int l = a[i].lp;
            int r = a[i].rp;
            int prevl = a[i-1].lp;
            int prevr = a[i-1].rp;
            int dis = a[i].time - a[i-1].time;

            if(prevl - dis > r) {
                watch(prevl)
                cerr << "failled on ind " << i << endl;
                ans = "NO";
                break;
            }

            if(prevr + dis < l) {
                cerr << "failed on ind " << i << endl;
                ans = "NO";
                break;
            }

            vector<int> thing = {prevl + dis, prevl-dis, prevr + dis, prevr-dis};
            sort(thing.begin(), thing.end());

            int lreach = thing[0];
            int rreach = thing[3];

            if(lreach > rreach) swap(lreach, rreach);
            
            watch(l)
            lreach = max(lreach, l);
            rreach = min(rreach, r);
            watch(lreach)
            watch(rreach)
            a[i].lp = lreach;
            a[i].rp = rreach;

            
            
        }

        cout << ans << endl;





    }
}