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

int seg[4*maxn];
int query(int l, int r, int ind, int tl, int tr) {
    if(l > r) return 0;
    if(tl > tr) return 0;

    // cerr << "on " << tl << " " << tr << endl;
    // watch(ind)

    if(l == tl and r == tr) {
        return seg[ind];
    } else {
        int tm = (tl+tr)/2;

        int res = query(l, min(tm, r), 2*ind, tl, tm);
        res += query(max(l, tm+1), r, 2*ind+1, tm+1, tr);

        return res;
    }
}

// increment
void incr(int pos, int val, int ind, int tl, int tr) {
    if(tl > tr) return;

    if(pos == tl and pos == tr) {
        seg[ind] += val;
        return;
    }

    int tm = (tl+tr)/2;

    cerr << "on " << tl << " " << tr << endl;
    if(pos <= tm) {
        incr(pos, val, 2*ind, tl, tm);
    } else {
        incr(pos, val, 2*ind+1, tm+1, tr);
    }

    seg[ind] = seg[2*ind] + seg[2*ind+1];
}

int n;
int a[maxn];
vector<int> cmp;
int cmpind = 0;
map<int, int> ac;
bool rev = false;

pii ans = {1e18, 1e18};
void go() {
    for(int i = 1; i <= n; i++) {
        incr(a[i], 1, 1, 1, cmpind);
    }

    for(int i = 1; i <= n; i++) {
        incr(a[i], -1, 1, 1, cmpind);

        if(query(a[i]+1, cmpind, 1, 1, cmpind) >= 2) {
            for(int j = i+1; j <= n; j++) {
                if(a[j] > a[i]) {
                    if(rev) cout << n-i+1 << " " << n-j+1 << endl;
                    else cout << i << " " << j << endl;
                    // ans = min(ans, {i, j});
                    exit(0);

                }
            }
        } 

        if(query(1, a[i]-1, 1, 1, cmpind) >= 2) {
            for(int j = i+1; j <= n; j++) {
                if(a[j] < a[i]) {
                    if(rev) cout << n-i+1 << " " << n-j+1 << endl;
                    else cout << i << " " << j << endl;
                    
                    exit(0);
                    // cout << i << " " << j << endl;
                    // ans = min(ans, {i, j});
                }
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cmp.emplace_back(a[i]);
    }

    sort(all(cmp));
    cmp.erase(unique(all(cmp)), cmp.end());

    for(int x: cmp) {
        ac[x] = ++cmpind;
    }

    for(int i = 1; i <= n; i++) {
        a[i] = ac[a[i]];
    }

    go();
    for(int i = 0; i < 4*maxn; i++) seg[i] = 0;
    reverse(a+1, a+n+1);
    rev = true;
    go();

    cout << -1 << endl;
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
