// https://codeforces.com/contest/371/problem/E

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

const int maxn = 300500;

int n, k;
pii a[maxn];
int psa[maxn];

// increasing coefficients
int incr[maxn];

// decreasing coefficeints
int decr[maxn];

int query(int arr[], int l, int r) {
    if(l > r) {
        assert(false);
        return 0;
    }

    return arr[r]-arr[l-1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }

    cin >> k;

    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i++) {
        cerr << a[i].fi << " " << a[i].se << endl;
    }
    
    // inc[i] starts from coefficient i
    // dec[i] starts from coefficient i-n
    for(int i = 1; i <= n; i++) {
        psa[i] = psa[i-1] + a[i].fi;
        incr[i] = incr[i-1] + i*a[i].fi;
        decr[i] = decr[i-1] + (i-n)*a[i].fi;
    }

    int mi = LLONG_MAX;
    int best = -1;
    for(int i = 1; i <= n-k+1; i++) {
        int loc = 0;

        // subtract to make it 0
        loc += query(incr, i, i+k-1) - (i)*query(psa, i, i+k-1);

        // add to make it -k+1
        int cur = i-n;
        int to = -k+1;

        loc += query(decr, i, i+k-1) + (to-cur)*query(psa, i, i+k-1);

        if(loc < mi) {
            mi = loc;
            best = i;
        }
    }

    for(int i = 0; i < k; i++) {
        cout << a[best+i].se << " ";
    }
    cout << endl;
}

/*

brute force k size contiguous subsegments
    - prove w exchange argument

sequence a[1], a[2], a[3], a[4], a[5] calculate pairwise sums

0*a[1] + -4*a[1]
1*a[2] + -3*a[1]
2*a[3] + -2*a[1]
3*a[4] + -1*a[1]
4*a[4] + 0*a[1]

0*a[1] + -1*a[1]
1*a[2] + 0*a[2]





*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
