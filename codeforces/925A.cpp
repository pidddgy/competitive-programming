// https://codeforces.com/contest/925/problem/A

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, cl, ce, v;
    cin >> n >> m >> cl >> ce >> v;

    int stairs[cl+1];
    for(int i = 1; i <= cl; i++) {
        cin >> stairs[i];
    }

    int ele[ce+1];
    for(int i = 1; i <= ce; i++) {
        cin >> ele[i];
    }

    sort(stairs+1, stairs+cl+1);
    sort(ele+1, ele+ce+1);

    int q;
    cin >> q;

    while(q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if(x1 == x2) {
            cout << abs(y1-y2) << endl;
            continue;
        }
        
        int l = 1;
        int r = cl;
        int lstair = -1;

        while(l <= r) {
            int m = (l+r)/2;

            if(stairs[m] < y1) {
                lstair = stairs[m];
                l = m+1;
            } else {
                r = m-1;
            }
        }

        l = 1, r = cl;
        int rstair = -1;

        while(l <= r) {
            int m = (l+r)/2;
            cerr << "on " << m << endl;
            if(stairs[m] < y1) {
                l = m+1;
            } else {
                rstair = stairs[m];
                r = m-1;
            }
        }

        l = 1, r = ce;
        int lele = -1;
        while(l <= r) {
            int m = (l+r)/2;

            if(ele[m] < y1) {
                lele = ele[m];
                l = m+1;
            } else {
                r = m-1;
            }
        }

        int rele = -1;
        l = 1, r = ce;
        while(l <= r) {
            int m = (l+r)/2;

            if(ele[m] < y1) {
                l = m+1;
            } else {
                rele = ele[m];
                r = m-1;
            }
        }

        int ans = INT_MAX;
        for(int x: set<int>({lstair, rstair})) {
            if(x==-1) continue;

            ans = min(ans, abs(y1-x)+abs(x1-x2)+abs(y2-x));
        }

        watch(lstair)
        watch(rstair)
        watch(lele)
        watch(rele)
        
        for(int x: set<int>({lele, rele})) {
            if(x==-1) continue;

            watch(abs(x1-x))
            watch((abs(y1-y2)+v-1)/v)
            watch(abs(x2-x))
            ans = min(ans, abs(y1-x)+((abs(x1-x2)+v-1)/v)+abs(y2-x));
        }

        cout << ans << endl;
    }
}