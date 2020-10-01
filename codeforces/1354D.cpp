// https://codeforces.com/contest/1354/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
const int maxn = 1000500;

int bit[maxn];

void upd(int n, int val) {
    for(int i = n; i < maxn-5; i += i & -i) {
        bit[i] += val;
    }
}

int query(int n) {
    int ret = 0;
    for(int i = n; i >= 1; i -= i & -i) {
        ret += bit[i];
    }

    return ret;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        upd(a, 1);
    }
    
    for(int i = 1; i <= q; i++) {
        int k;
        cin >> k;
        cerr << "a" << endl;

        if(k < 0) {
            k = abs(k);
            cerr << "aa" << endl;

            int l = 1;
            int r = 1000000;
            int lastgood = -1;
            while(l <= r) {
                int m = (l+r)/2;

                if(query(m) >= k) {
                    r = m-1;
                    lastgood = m;
                } else {
                    l = m+1;
                }
            }

            cerr << "updating -1 to " << lastgood << endl;
            upd(lastgood, -1);
        } else {
            upd(k, 1);
        }
    }

    for(int i = 1; i <= 1000000; i++) {
        if(query(i)) {
            cout << i << endl;
            return 0;
        }
    }

    cout << 0 << endl;
}