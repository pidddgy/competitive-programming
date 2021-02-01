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
int cur = 0;

int seg[3*maxn];

void upd(int pos, int val) {
    pos += cur;
    seg[pos] = val;

    for(int i = pos/2; i >= 1; i /= 2) {
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

int query(int l, int r) {
    l += cur;
    r += cur;

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

    int n, t;
    cin >> n >> t;
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector<int> cmp;

    int sum = 0;
    for(int i = 0; i <= n; i++) {
        sum += a[i];
        // S.emplace(sum);
        cmp.emplace_back(sum);
    }
    // cerr << endl;
    sort(all(cmp));
    cmp.erase(unique(all(cmp)), cmp.end());

    cur = sz(cmp);
    int ans = 0;
    sum = 0;
    upd((lower_bound(all(cmp), 0) - cmp.begin())+1, 1);

    for(int i = 1; i <= n; i++) {
        sum += a[i];

        int rem = -(t-sum-1);

        int ind;    
        auto ree = lower_bound(all(cmp), rem);

        if(ree != cmp.end()) {
            ind = ree-cmp.begin()+1;
            cerr << "querying " << ind << " " << cur << endl;
            ans += query(ind, cur);
        }

        ind = (lower_bound(all(cmp), sum) - cmp.begin())+1;
        int old = query(ind, ind);
        upd(ind, old+1);
    }

    cout << ans << endl;
}

/*

rem = minimum element you can subtract


find all with less than or equal to

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
