// https://codeforces.com/contest/749/problem/D

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
int ma[maxn];
pii s[maxn];
int seg[3*maxn];
set<int> S[maxn];

void upd(int pos, int val) {
    pos++;
    pos += n;
    seg[pos] = val;

    for(int i = pos/2; i >= 1; i /= 2) {
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

int query(int l, int r) {
    l++;
    r++;
    l += n;
    r += n;

    int res = 0;
    while(l <= r) {
        if(l%2 == 1) res += seg[l++];
        if(r%2 == 0) res += seg[r--];

        l /= 2;
        r /= 2;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;

        ma[a] = max(ma[a], i);
        s[i] = pii(a, b);
        S[a].emplace(b);
    }

    for(int i = 1; i <= n; i++) {
        if(ma[i] != 0) {
            upd(ma[i], 1);
        }
    }

    int q;
    cin >> q;

    upd(0, 1);
    while(q--) {
        int k;
        cin >> k;

        vector<int> v(k);
        for(int i = 0; i < k; i++) {
            cin >> v[i];
        }

        // remove
        for(int x: v) {
            if(ma[x] == 0) continue;
            upd(ma[x], 0);
        }

        int l = 0;
        int r = n;

        int lgood = -1;
        while(l <= r) {
            int mid = (l+r)/2;

            if(query(mid, n) >= 2) {
                lgood = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        int lgood2 = -1;
        l = 0;
        r= n;
        while(l <= r) {
            int mid = (l+r)/2;

            if(query(mid, n)) {
                lgood2 = mid;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        if(lgood == -1) {
            cout << "0 0" << endl;
        } else {
            int person = s[lgood2].fi;
            int ree = s[lgood].se;
            int bid = *S[person].upper_bound(ree);

            cout << person << " " << bid << endl;

        }

        // put back
        for(int x: v) {
            if(ma[x] == 0) continue;
            cerr << "adding to " << ma[x] << endl;
            upd(ma[x], 1);
        }

        cerr << endl << endl;
    }
}

/*

find second last, print +1 -> only maintain max bid of each person
segment tree on max bids

all unique, can compress

for each query
    remove all in query

    bsearch rightmost with >= 2 suffix sum
    
    put back

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
