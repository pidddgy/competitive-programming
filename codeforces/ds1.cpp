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

const int maxn = 100500;

int n, m;
int a[maxn];
int seg[4*maxn];
int seg2[4*maxn];

void upd(int arr[], int pos, int val) {
    pos += 1e5;

    arr[pos] = val;
    for(int i = pos/2; i >= 1; i /= 2) {
        arr[i] = arr[i*2] + arr[(i*2) | 1LL];
    };
}

int query(int arr[], int l, int r) {
    l += 1e5;
    r += 1e5;

    int res = 0;
    while(l <= r) {
        if(l%2 == 1) {
            res += arr[l++];
        }

        if(r%2 == 0) {
            res += arr[r--];
        }

        l /= 2;
        r /= 2;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        upd(seg, i, x);

        int old = query(seg2, x, x);

        cerr << "updating " << x << " to " << old+1 << endl;
        upd(seg2, x, old+1);
    }   

    while(m--) {
        char t;
        cin >> t;

        if(t == 'C') {
            int pos, val;
            cin >> pos >> val;

            int cur = query(seg, pos, pos);
            upd(seg, pos, val);

            int ree = query(seg2, cur, cur);
            int old = query(seg2, val, val);

            // remove
            upd(seg2, cur, ree-1);

            upd(seg2, val, old+1);
        } 

        if(t == 'S') {
            int l, r;
            cin >> l >> r;

            cout << query(seg, l, r) << endl;
        }

        if(t == 'Q') {
            int v;
            cin >> v;

            cout << query(seg2, 1, v) << endl;
        }
    }
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
