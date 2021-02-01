// https://codeforces.com/contest/1250/problem/J

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

const int maxn = 30050;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
int cpy[maxn];
int c[maxn];

int n, k;
void reset() {
    for(int i = 0; i <= n; i++) {
        c[i] = cpy[i];
    }
}

void solve() {
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> cpy[i];
    }
    reset();

    int l = 1, r = 2e12;
    int lgood = 0;

    int it = 0;
    while(l <= r) {
        reset();
        
        int mid = (l + r)/2;

        int rows = 0;     
        for(int i = 1; i <= n; i++) {
            if(c[i-1] + c[i] >= mid) {
                rows++;
                c[i] -= mid-c[i-1];
                c[i-1] = 0;
            }

            rows += c[i]/mid;

            if(rows >= k) break;
            c[i] %= mid;
        }   

        if(rows >= k) {
            l = mid+1;
            lgood = mid;
        } else {
            r = mid-1;
        }
        it++;

        assert(it <= 100);
    }

    cout << k*lgood << endl;
}   

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

binary search for maximum number of columns possible

use previous, then use current alone

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
