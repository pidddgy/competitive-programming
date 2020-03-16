// https://codeforces.com/contest/1241/problem/C

#include <bits/stdc++.h>
#define ld long double
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define ll long long
using namespace std;

long long per(ll a, ll b) {
    ld c = (ld)a/100.0;

    return b * c;
}
int main() {
    #define int long long

    // cout << ((double)138 / (double)100) * 100 << endl;
    int q;
    cin >> q;

    while(q--) {
        int n;
        cin >> n;

        int p[n+1];
        for(int i = 1; i <= n; i++) cin >> p[i];

        int x, a, y, b;
        cin >> x >> a >> y >> b;
        
        int k;
        cin >> k;
        // watch(k)

        sort(p+1, p+n+1, greater<int>());

        bool found = false;
        for(int i = 1; i <= n; i++) {
            int have = 0;

            int overlap = i/(a*b);
            int xonly = (i/a) - overlap;
            int yonly = (i/b) - overlap;

            // watch(i);
            // watch(overlap)
            // watch(xonly)
            // watch(yonly)
            for(int j = 1; j <= i; j++) {
                if(overlap) {
                    // cout << "HI" << endl;
                    have += per(x+y, p[j]);
                    // cout << "adding" << per(x+y, p[j]) << endl;
                    // watch(x+y)
                    // watch(p[j])
                    overlap--; 
                } else if(x > y) {
                    if(xonly) {
                        have += per(x, p[j]);
                        xonly--;
                    } else if(yonly) {
                        have += per(y, p[j]);
                        yonly--;
                    }
                } else {
                    if(yonly) {
                        have += per(y, p[j]);
                        yonly--;
                    } else if(xonly) {
                        have += per(x, p[j]);
                        xonly--;
                    }
                }

            }

            // watch(i)
            // watch(have)
            // watch(k)

            if(have >= k) { 
                found = true;
                cout << i << endl;
                break;
            }

            if(found) break;
        }


        if(!found) cout << -1 << endl;

    }
}