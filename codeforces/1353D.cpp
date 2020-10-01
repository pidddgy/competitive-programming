// https://codeforces.com/contest/1353/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

struct Compare {
    bool operator()(pii &l, pii &r) {
        // if((l.se-l.fi) > (r.se-r.fi)) {
        //     return false;
        // }
        if((l.se-l.fi) == (r.se-r.fi)) {
            return l > r;
        }
        return (l.se-l.fi) < (r.se-r.fi);
    }
};
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    // priority_queue<pii, vector<pii>, Compare> test;

    // test.push(pii(1, 2));
    // test.push(pii(4, 6));
    // test.push(pii(1, 3));


    // while(test.size()) {
    //     cout << test.top().fi << " " << test.top().se << endl;
    //     test.pop();
    // }

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[n+1];
        for(int i = 1; i <= n; i++) {
            a[i] = 0;
        }

        priority_queue<pii, vector<pii>, Compare> Q;
        Q.push(pii(1, n));

        int cur = 1;
        while(!Q.empty()) {
            pii x = Q.top(); Q.pop();
            int l = x.fi, r = x.se;
            // watch(l)
            // watch(r)
            a[(l+r)/2] = cur;

            pii nextL = pii(l, ((l+r)/2)-1);
            pii nextR = pii(((l+r)/2)+1, r);
            
            cerr << l << "," << r << endl;
            cerr << nextL.fi << "," << nextL.se << endl;
            cerr << nextR.fi << "," << nextR.se << endl;
            if((r-l)+1 > 1) {
                if((((r-l)+1))%2==0) {
                    if((nextR.fi <= nextR.se)) {
                        Q.push(nextR);
                    }

                    if(nextL.fi <= nextL.se) {
                        Q.push(nextL);
                    }
                } else {
                    if(nextL.fi <= nextL.se) {
                        Q.push(nextL);
                    }

                    if((nextR.fi <= nextR.se)) {
                        Q.push(nextR);
                    }
                }
            }

            cur++;
            for(int i = 1; i <= n; i++) {
                cerr << a[i] << " ";
            }
            cerr << endl;
        }

        for(int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}