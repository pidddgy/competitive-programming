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

int seg[4*maxn], seg2[4*maxn];

void incr(int arr[], int pos, int val, int ind, int cl, int cr) {
    if(cl > cr) return;

    if(cl == cr) {
        arr[ind] += val;
        return;
    }

    int cm = (cl+cr)/2;

    if(pos <= cm) {
        incr(arr, pos, val, 2*ind, cl, cm);
    } else {
        incr(arr, pos, val, 2*ind+1, cm+1, cr);
    }

    arr[ind] = arr[2*ind] + arr[2*ind+1];
}

int query(int arr[], int l, int r, int ind, int cl, int cr) {
    if(l > r) return 0;
    if(cl > cr) return 0;

    if(l == cl and cr == r) {
        return arr[ind];
    }

    int cm = (cl+cr)/2;
    return query(arr, l, min(cm, r), 2*ind, cl, cm) + query(arr, max(l, cm+1), r, 2*ind+1, cm+1, cr);
}

int a[maxn];
vector<int> cmp;
int curc = 0;
map<int, int> ac;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    int n;
    cin >> n;    

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cmp.emplace_back(a[i]);
    }

    sort(all(cmp));
    for(int i = 0; i < sz(cmp); i++) {
        ac[cmp[i]] = i+1;
        curc++;
    }

    for(int i = 1; i <= n; i++) {
        a[i] = ac[a[i]];
        cerr << a[i] << " ";
    }
    cerr << endl;

    for(int i = 1; i <= n; i++) {
        incr(seg2, a[i], 1, 1, 1, curc);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int l = query(seg, a[i]+1, curc, 1, 1, curc);
        int r = query(seg2, a[i]+1, curc, 1, 1, curc);

        if(max(l, r) > 2*min(l, r)) {
            cerr << i << " " << l << "," << r << endl;
            ans++;
        }
        
        incr(seg, a[i], 1, 1, 1, curc);
        incr(seg2, a[i], -1, 1, 1, curc);
    }

    cout << ans << endl;
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
