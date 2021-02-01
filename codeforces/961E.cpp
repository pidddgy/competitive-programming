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
int a[maxn];
vector<int> rem[maxn];

int seg[4*maxn];

void upd(int pos, int val) {
    pos += 2e5;
    seg[pos] += val;

    for(int i = pos/2; i >= 1; i /= 2) {
        seg[i] = seg[i*2] + seg[i*2+1];
    }
}

int query(int l, int r) {
    l += 2e5, r += 2e5;
    int res = 0;

    while(l <= r) {
        if (l%2 == 1) res += seg[l++];
        if (r%2 == 0) res += seg[r--];
        l /= 2; r /= 2;
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int x: rem[i]) {
            upd(x, -1);
        }

        cin >> a[i];
        a[i] = min(a[i], (int)2e5);

        int val = query(1, a[i]);
        ans += val;

        // in this range, if any has a[j] >= i it is possible
        if(a[i]+1 > i) {
            upd(i, 1);
            rem[a[i]+1].emplace_back(i);
        }
    }   

    cout << ans << endl;
}

/*

implicit bound: a[i] <= n

ds bash?

difference array-like thing

everything > a[i] can be considered to be a y
query from 1..a[i]-1

consider if season can be i and episode can be 1...a[i]

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
