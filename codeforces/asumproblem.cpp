#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

int N;

int ans = 0;

// int cache[(int)1e7+5];

int cum = 0;
int query(int x) {
    // if(cache[x] != -1) return cache[x];
    cum++;

    assert(cum <= 5e5);
    cout << "? " << x << endl;
    cout.flush();
    int res;
    cin >> res;
    return res;
}


void f(int l, int r, int lo, int hi) {
    if(l > r) return;
    assert(lo <= hi);
    int mid = (lo+hi+1)/2;

    // how many elements guaranteed to be above?
    int ab = N-r;

    if(l == r) {
        int lgood = -1;
        // largest number where answer is positive
        while(lo <= hi) {
            int md = (lo+hi)/2;
            int res = query(md);

            if(res-ab >= 1) {
                lgood = md;
                lo = md+1;
            } else {
                hi = md-1;
            }
        }

        ans += lgood;
        return;
    }

    if(lo == hi) {
        ans += (r-l+1) * lo;
        return;
    }

    int res = query(mid);

    int gr = res - ab;
    int less = (r-l+1)-gr;
    
    f(l, l+less-1, lo, mid-1);
    f(r-gr+1, r, mid, hi);
}

signed main() {
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    mt19937 mt(seed);
    cin >> N;

    f(1, N, 0, 1e7);
    cout << "! " << ans << endl;
}

/*

recursion

imagine sorted array

f(l, r, lo, hi)
throw out any segments that dont have any

bsearch each element: n*log(1e7)


2
0 9

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?