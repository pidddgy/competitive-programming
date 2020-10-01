// https://codeforces.com/contest/1023/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = (int)2e5+500;

int a[maxn];
int seg[maxn*4];
int n, q;

void upd(int pos, int val, int ind = 1, int cl = 1, int cr = n) {
    if(cl == cr) {
        seg[ind] = val;
    } else {
        int cm = (cl+cr)/2;
        if(pos <= cm) {
            upd(pos, val, ind*2, cl, cm);
        } else {
            upd(pos, val, ind*2+1, cm+1, cr);
        }

        seg[ind] = min(seg[ind*2], seg[ind*2+1]);
    }
}

int query(int l, int r, int ind = 1, int cl = 1, int cr = n) {
    if(l > r) return INT_MAX;
    else if(cl == l and cr == r) return seg[ind];

    int cm = (cl+cr)/2;

    return min(query(l, min(cm, r), ind*2, cl, cm),
                query(max(l, cm+1), r, ind*2+1, cm+1, cr));
}

// stores first and last positions of each element
pii pos[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;

    for(int i = 1; i <= q; i++) pos[i] = {INT_MAX, INT_MIN};

    bool have0 = false;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            a[i] = INT_MAX;
            have0 = true;
        }

        upd(i, a[i]);
        
        if(a[i] != INT_MAX) {
            pos[a[i]].fi = min(pos[a[i]].fi, i);
            pos[a[i]].se = max(pos[a[i]].se, i);
        }
    }

    if(pos[q] == pii(INT_MAX, INT_MIN)) {
        if(!have0) {
            cout << "NO" << endl;
            return 0;
        } else {
            for(int i = 1; i <= n; i++) {
                if(a[i] == INT_MAX) {
                    a[i] = q;
                    break;
                }
            }
        }
    }

    for(int i = 1; i <= q; i++) {
        cerr << "querying " << pos[i].fi << " " << pos[i].se << endl;
        if(query(pos[i].fi, pos[i].se) < i and pos[i] != pii(INT_MAX, INT_MIN)) {
            cout << "NO" << endl;
            return 0;
        }
    }

    a[0] = 1;

    for(int i = 1; i <= n; i++) {
        if(a[i] == INT_MAX) {
            a[i] = a[i-1];
        }
    }

    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

/*

if we see a smaller number in between two occurences of a bigger number it is invalid

e.g. 6666666662222266

0 is an exception and can be put anywhere (store as INT_MAX)

wee min segtree time




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
