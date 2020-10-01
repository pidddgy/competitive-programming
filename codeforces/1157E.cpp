// https://codeforces.com/contest/1157/problem/E

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

const int maxn = 200500;
int n;

int a[maxn], cnt[maxn], ans[maxn];
int seg[3*maxn];

// iterative segtree implementation

void upd(int pos, int val) {
    pos += n;
    seg[pos] = val;

    for(int i = pos/2; i >= 1; i /= 2) {
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

int query(int l, int r) {
    l += n, r += n;
    int res = 0;

    while(l <= r) {
        if (l%2 == 1) res += seg[l++];
        if (r%2 == 0) res += seg[r--];
        l /= 2; r /= 2;
    }

    return res;
}

int bsearch(int l, int r) {
    int lgood = -1;
    int b = l;
    while(l <= r) {
        int mid = (l+r)/2;

        if(query(b, mid)) {
            lgood = mid;
            r = mid-1; 
        } else {
            l = mid+1;
        }
    }

    return lgood;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }


    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for(int i = 0; i < n; i++) {
        upd(i, cnt[i]);
    }

    for(int i = 1; i <= n; i++) {
        int use;

        if(bsearch(n-a[i], n-1) != -1) {
            use = bsearch(n-a[i], n-1);
        } else if(bsearch(0, n-a[i]-1) != -1) {
            use = bsearch(0, n-a[i]-1);
        } else {
            assert(false);
        }

        cnt[use]--;
        upd(use, cnt[use]);
        ans[i] = (a[i]+use)%n;
    }   

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
