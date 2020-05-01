// https://codeforces.com/contest/722/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
// #define cerr if(false) cerr

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

int a[maxn];
node seg[3*maxn];
int n;

void build() {
    for(int i = n-1; i > 0; --i) {
        node l = seg[i<<1];
        node r = seg[(i<<1) + 1];

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

        seg[p>>1].sum = l.sum+r.sum;
        seg[p>>1].pref = max(l.pref, l.sum+r.pref);
        seg[p>>1].suf = max(r.suf, r.sum+l.pref);
        seg[p>>1].ma = max({seg[p>>1].pref, seg[p>>1].suf, l.ma, r.ma, l.suf+r.pref});

        for(int i = 0; i < n*2; i++) {
            cerr << seg[i].ma << " ";
        }
        cerr << endl;
    }
}



signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int _;
        cin >> _;

        seg[i+n].ma = seg[i+n].pref = seg[i+n].suf = seg[i+n].sum = _;
    }

    build();
    for(int i = 0; i < n*2; i++) {
        cerr << seg[i].ma << " ";
    }
    cerr << endl;

    for(int i = 0; i < n; i++) {
        int q;
        cin >> q;

        upd(q-1, -1e5);

        for(int i = 0; i < n*2; i++) {
            cerr << seg[i].ma << " ";
        }
        cerr << endl;

        cout << seg[1].ma << endl;
        cerr << endl;
    }


}

/*

seg[i].sum = l.sum + r.sum;
seg[i].pref = max(l.pref, l.sum+r.pref);
seg[i].suf = max(r.suf, r.sum+l.suf);
seg[i].ma = max({cur.pref, cur.suf, l.ma, r.ma, l.suf+r.pref});

*/