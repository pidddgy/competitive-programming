// https://atcoder.jp/contests/abc170/tasks/abc170_e

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define cerr if(false) cerr
const int maxn = 200500;

multiset<int> arr[maxn];
int seg[maxn*4];
int N, Q;
void upd(int pos, int val, int ind=1, int l=1, int r=2e5) {
    if(l == r) {
        seg[ind] = val;
    } else {
        int m = (l+r)/2;
        if(pos <= m) {
            upd(pos, val, ind*2, l, m);
        } else {
            upd(pos, val, ind*2+1, m+1, r);
        }

        seg[ind] = min(seg[ind*2], seg[ind*2+1]);
    }
}

int query(int l, int r, int ind=1, int cl=1, int cr=2e5) {
    if(l > r) {
        return INT_MAX;
    }
    
    if(cl == l and cr == r) {
        return seg[ind];
    }

    int cm = (cl+cr)/2;
    return min(query(l, cm, ind*2, cl, cm),
            query(cm+1, r, ind*2+1, cm+1, cr));
}

int A[maxn], B[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;

    for(int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;

        arr[b].emplace(a);
        A[i] = a;
        B[i] = b;
    }

    for(int i = 1; i <= 2e5; i++) {
        if(arr[i].size()) {
            upd(i, *arr[i].rbegin());
        } else {
            upd(i, INT_MAX);
        }
    }

    for(int i = 1; i <= Q; i++) {
        int c, d;
        cin >> c >> d;

        int k = B[c];
        arr[k].erase(arr[k].lower_bound(A[c]));
        
        if(arr[k].size()) {
            upd(k, *arr[k].rbegin());
        } else {
            upd(k, INT_MAX);
        }

        arr[d].emplace(A[c]);
        upd(d, *arr[d].rbegin());

        B[c] = d;

        cout << query(1, 200000) << endl;
    }
}
