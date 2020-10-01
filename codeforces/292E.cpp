// https://codeforces.com/contest/292/problem/E 

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 100500;

int n, m;

pii seg[maxn*4];
bool marked[maxn*4];
int a[maxn], b[maxn];

int left(int n) {
    return n*2;
}

int right(int n) {
    return n*2+1;
}

void push_down(int v) {
    if(marked[v]) {
        seg[left(v)] = seg[right(v)] = seg[v];
        marked[left(v)] = marked[right(v)] = true;
        marked[v] = false;
    }
}

void upd(int l, int r, pii val, int v = 1, int tl = 1, int tr = n) {
    if(l > r) {
        return;
    }
    
    if(l == tl and r == tr) {
        seg[v] = val;
        marked[v] = true;
    } else {
        push_down(v);
        int tm = (tl+tr)/2;

        upd(l, min(r, tm), val, left(v), tl, tm);
        upd(max(l, tm+1), r, val, right(v), tm+1, tr);
    }
}

pii query(int pos, int v = 1, int tl = 1, int tr = n) {
    if(tl == tr) {
        return seg[v];
    }

    push_down(v);
    int tm = (tl+tr)/2;
    if(pos <= tm) {
        return query(pos, left(v), tl, tm);
    } else {
        return query(pos, right(v), tm+1, tr);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    upd(1, n, {-1, -1});

    for(int q = 1; q <= m; q++) {
        int t;
        cin >> t;

        if(t == 1) {
            int x, y, k;
            cin >> x >> y >> k;

            upd(y, y+k-1, pii(x, y));
        } else if(t == 2) {
            int x;
            cin >> x;

            pii val = query(x);

            if(val == pii(-1, -1)) {
                cout << b[x] << endl;
            } else {
                cout << a[val.fi + (x-val.se)] << endl;
            }
        }
    }
}
