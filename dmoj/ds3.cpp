// https://dmoj.ca/problem/ds3

#include <bits/stdc++.h>
using namespace std;

#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#pragma GCC optimize "Ofast"
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 100500;

int gcd(int x, int y) {
    if(x == 0) return y;
    if(y == 0) return x;
    return y ? gcd(y, x%y) : x;
}

int a[maxn];
int mseg[maxn*4], gseg[maxn*4];
pii qseg[maxn*4];

pair<int, int> combine(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) 
        return a;
    if (b.first < a.first)
        return b;
    return make_pair(a.first, a.second + b.second);
}


int left(int n) {return n*2;}
int right(int n) {return n*2+1;}

int N, M;
void mupdate(int i, int v, int ind = 1, int l = 1, int r = N) {
    if(l == r) {
        mseg[ind] = v;
    } else {
        int m = (l+r)/2;
        if(i <= m) {
            mupdate(i, v, left(ind), l, m);
        } else {
            mupdate(i, v, right(ind), m+1, r);
        }
        mseg[ind] = min(mseg[left(ind)], mseg[right(ind)]);
    }
}

void gupdate(int i, int v, int ind = 1, int l = 1, int r = N) {
    if(l == r) {
        gseg[ind] = v;
    } else {
        int m = (l+r)/2;
        if(i <= m) {
            gupdate(i, v, left(ind), l, m);
        } else {
            gupdate(i, v, right(ind), m+1, r);
        }
        gseg[ind] = gcd(gseg[left(ind)], gseg[right(ind)]);
    }
}

void qupdate(int i, int v, int ind = 1, int l = 1, int r = N) {
    if(l != r) {
        int m = (l+r)/2;
        if(i <= m) {
            qupdate(i, v, left(ind), l, m);
        } else {
            qupdate(i, v, right(ind), m+1, r);
        }
        qseg[ind] = combine(qseg[left(ind)], qseg[right(ind)]);
    } else {
        qseg[ind] = pii(v, 1);
    }
}

int mquery(int tl, int tr, int l, int r, int ind = 1) {
    if(tl > r or tr < l) {
        return INT_MAX-100;
    } else if(l <= tl and tr <= r) {
        return mseg[ind];
    }

    int m = (tl+tr)/2;
    return min(mquery(tl, m, l, r, left(ind)), mquery(m+1, tr, l, r, right(ind)));
}

int gquery(int tl, int tr, int l, int r, int ind = 1) {
    if(tl > r or tr < l) {
        return 0;
    } else if(l <= tl and tr <= r) {
        return gseg[ind];
    }

    int m = (tl+tr)/2;

    int lv = gquery(tl, m, l, r, left(ind));
    int rv = gquery(m+1, tr, l, r, right(ind));

    return gcd(lv, rv);
}

pii qquery(int tl, int tr, int l, int r, int v, int ind = 1) {
    if(tl > r or tr < l) {
        return pii(INT_MAX, 0);
    } else if(l <= tl and tr <= r) {
        return qseg[ind];
    }

    int m = (tl+tr)/2;

    pii lv = qquery(tl, m, l, r, v, left(ind));
    pii rv = qquery(m+1, tr, l, r, v, right(ind));

    return combine(lv, rv);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        int x;
        cin >> x;

        gupdate(i, x);
        mupdate(i, x);
        qupdate(i, x);
    }   

    for(int i = 1; i <= M; i++) {
        char type;
        cin >> type;

        if(type == 'C') {
            int x, v;
            cin >> x >> v;

            gupdate(x, v);
            mupdate(x, v);
            qupdate(x, v);
        } else if(type == 'M') {
            int l, r;
            cin >> l >> r;

            cout << mquery(1, N, l, r) << endl;
        } else if(type == 'G') {
            int l, r;
            cin >> l >> r;

            cout << gquery(1, N, l, r) << endl;
        } else if(type == 'Q') {
            int l, r;
            cin >> l >> r;

            int val = gquery(1, N, l, r);

            pii mi = qquery(1, N, l, r, val);
            watch(val)
            cerr << mi.fi << "," << mi.se << endl;

            if(val == mi.fi) {
                cout << mi.se << endl;
            } else {
                cout << 0 << endl;
            }
            // cerr << mi.fi << "," << mi.se << endl;
            cerr << endl;

            // cout << qquery(1, N, l, r, val) << endl;
        }
    } 
}