// https://codeforces.com/contest/722/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define int long long
// #define cerr if(false) cerr
const int NINF = -1E14-10000000;

int q;
struct node {
    int sum;
    int pref;
    int suf;
    int ma;

    node(int summ = 0, int preff = 0, int suff = 0, int maa = 0) {
        sum = summ;
        pref = preff;
        suf = suff;
        ma = maa;
    }
};

const int maxn = 100500;

int a[maxn*5];
node seg[10*maxn];
int n;

void build() {
    for(int i = n-1; i > 0; --i) {
        node l = seg[i<<1LL];
        node r = seg[(i<<1LL) + 1];

        seg[i].sum = l.sum + r.sum;
        seg[i].pref = max(l.pref, l.sum+r.pref);
        seg[i].suf = max(r.suf, r.sum+l.suf);
        seg[i].ma = max({seg[i].pref, seg[i].suf, l.ma, r.ma, l.suf+r.pref});
    }
}

void upd(int p, int val) {
    p += n;
    seg[p].ma = seg[p].sum = seg[p].suf = seg[p].pref = val;
    for(; p > 1; p >>= 1) {
        node l;
        node r;
        if(p % 2 == 0) {
            l = seg[p];
            r = seg[p^1];
        } else {
            l = seg[p^1];
            r = seg[p];
        }

        seg[p>>1LL].sum = l.sum+r.sum;

        int c = l.sum+r.pref;
        if(l.sum == NINF or r.pref == NINF) {
            c = NINF;
        }
        seg[p>>1LL].pref = max(l.pref, c);

        c = r.sum+l.suf;
        if(r.sum == NINF or l.suf == NINF) {
            c = NINF;
        }

        seg[p>>1LL].suf = max(r.suf, c);

        c = l.suf+r.pref;
        if(l.suf == NINF or r.pref == NINF) {
            c = NINF;
        }
        seg[p>>1LL].ma = max({seg[p>>1LL].pref, seg[p>>1LL].suf, l.ma, r.ma, c});

        for(int i = 0; i < n*2; i++) {
            cerr << seg[i].ma << " ";
        }
        cerr << endl;
    }
}

int query(int l, int r) {
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        l++;
        if(l&1) {
            res = max(res, seg[l].ma);
            cerr << "adding " << l << endl;
        }
        if(r&1) {
            res = max(res, seg[r].ma);
            cerr << "adding " << r << endl;
        } 
        --r;
    }

    return res;
}



signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    int inc = powl(2LL, ceil(log(n)/log(2LL)));

    // cout << "inc is " << inc << endl;

    for(int i = 0; i < n; i++) {
        int _;
        cin >> _;

        seg[i+inc].ma = seg[i+inc].pref = seg[i+inc].suf = seg[i+inc].sum = _;
    }

    n = inc;

    build();
    for(int i = 0; i < n*2; i++) {
        cerr << seg[i].ma << " ";
    }
    cerr << endl;

    for(int i = 0; i < q; i++) {
        char type;
        cin >> type;

        if(type == 'S') {
            int I, X;
            cin >> I >> X;

            upd(I, X);
        } else if(type == 'Q') {
            int l, r;
            cin >> l >> r;

            for(int j = 0; j < inc*2; j++) {
                cerr << seg[j].ma << " ";
            }
            cerr << endl;

            cout << query(l-1, r-1) << endl;
        }
    }


}

/*

seg[i].sum = l.sum + r.sum;
seg[i].pref = max(l.pref, l.sum+r.pref);
seg[i].suf = max(r.suf, r.sum+l.suf);
seg[i].ma = max({cur.pref, cur.suf, l.ma, r.ma, l.suf+r.pref});

*/