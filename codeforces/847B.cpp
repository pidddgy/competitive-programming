// https://codeforces.com/contest/847/problem/B

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
const int maxn = 200500;

int seg[4*maxn];
int a[maxn];
int n;

void upd(int pos, int val, int ind=1, int l=1, int r=n) {
    if(l == r) {
        seg[ind] = val;
    } else {
        int m = (l+r)/2;
        if(pos <= m) {
            upd(pos, val, ind*2, l, m);
        } else {
            upd(pos, val, ind*2+1, m+1, r);
        }

        seg[ind] = max(seg[ind*2], seg[ind*2+1]);
    }
}

int query(int l, int r, int ind=1, int cl=1, int cr=n) {
    if(l > r) {
        return -1;
    }
    
    if(cl == l and cr == r) {
        return seg[ind];
    }

    int cm = (cl+cr)/2;
    return max(query(l, cm, ind*2, cl, cm),
            query(cm+1, r, ind*2+1, cm+1, cr));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        upd(i, x);
        a[i] = x;
    }

    int used = 0;
    int deb = 0;
    while(used < n) {
        int cur = -1;
        for(;;) {

            int l = 1;
            int r = n;
            int lgood = -1;
            while(l <= r) {
                int m = (l+r)/2;
                int q = query(max(1, cur), m);
                if((q >= a[cur] or cur == -1) and q != -1) {
                    r = m-1;
                    lgood = m;
                } else {
                    l = m+1;
                }
            }

            if(lgood == -1) break;

            cout << a[lgood] << " ";
            upd(lgood, INT_MIN);
            used++;
            cur = lgood;
        }
        cout << endl;
    }
}