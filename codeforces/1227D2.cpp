// https://codeforces.com/contest/1227/problem/D2

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

int a[maxn];
int seg[3*maxn];

int n;

// iterative segtree
void upd(int pos, int val) {
    pos += 2e5;
    seg[pos] = val;
    
    for(int i = pos/2; i >= 1; i /= 2) {
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

int query(int l, int r) {
    l += 2e5, r += 2e5;
    int res = 0;

    while(l <= r) {
        if(l%2 == 1) res += seg[l++];
        if(r%2 == 0) res += seg[r--];

        l /= 2;
        r /= 2;
    }

    return res;
}

set<int> S;
map<int, int> cmp, rcmp;
int curc = 1;

// compare array values
bool comp(pii &l, pii &r) {
    if(l.fi == r.fi) {
        return l.se < r.se;
    }

    return l.fi > r.fi;
}

struct Query {
    int k, pos, ind;

    Query(int kk, int poss, int indd) {
        k = kk;
        pos = poss;
        ind = indd;
    }
};

bool compQuery(Query &l, Query &r) {
    return l.k < r.k;
}

vector<Query> queries;
int ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pii> vals;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        vals.emplace_back(a[i], i);
        S.emplace(a[i]);
    }

    for(int x: S) {
        cmp[x] = curc;
        rcmp[curc] = x;
        curc++;
    }

    for(int i = 0; i < sz(vals); i++) {
        vals[i].fi = cmp[vals[i].fi];
    }

    sort(all(vals), comp);

    int m;
    cin >> m;

    for(int i = 1; i <= m; i++) {
        int k, pos;
        cin >> k >> pos;

        queries.emplace_back(k, pos, i);
    }

    sort(all(queries), compQuery);
    int cur = 0;

    for(Query q: queries) {
        while(cur < q.k) {
            int pre = query(vals[cur].se, vals[cur].se);
            upd(vals[cur].se, pre+1);
            cur++;
        }

        int l = 1;
        int r = 2e5;
        int lgood = -1;

        // binary search for index we have to go up to
        while(l <= r) {
            int mid = (l+r)/2;

            if(query(1, mid) >= q.pos) {
                lgood = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        ans[q.ind] = a[lgood];
        cerr << endl;

    }

    for(int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
}

/*

the optimal subsequence is unique

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
