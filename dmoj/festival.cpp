// https://dmoj.ca/problem/dmopc19c3p5

#include <bits/stdc++.h>
#define int long long
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

// thank u gfg
int m(int n, int x) {
    bool neg = (n<0);
    n = abs(n);
    
    n = n + x/2;
    n = n - (n%x);

    if(neg) return n*-1;
    return n;
}

signed main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> a;
    for(int i = 1; i <= N; i++) {
        int b;
        cin >> b;

        a.emplace_back(b);
    }

    int incr = 0;

    while(Q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int d;
            cin >> d;

            a.emplace_back(d);
        } else if(type == 2) {
            int d;
            cin >> d;

            for(int i = 0; i < a.size(); i++) a[i] += d;
        } else if(type == 3) {
            int d;
            cin >> d;
            int res = 0;
            // watch(incr)

            for(int i = 0; i < a.size(); i++) {
                int val = a[i];
                res += abs(m(val, d)-val);
                // cout << "would set " << val << " to " << m(val, d) << endl;
            }

            cout << res << endl;
            // cout << endl;
        }
    }

}