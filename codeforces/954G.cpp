// https://codeforces.com/contest/954/problem/G

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
#define int long long
#define ull unsigned long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}


const int maxn = 500500;
int n, r, k;

int a[maxn];
int d[maxn];
ull tmp[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int len = 2*r+1;
    for(int i = 1; i <= n; i++) {
        d[max(1LL, i-r)] += a[i];

        if(i+r+1 <= n)
        d[i+r+1] -= a[i];
    }

    int l = 1;
    ull r = (1000500000000000000);
    // ull r = 500;
    r += 40;
    // watch(r)


    int ans = 0;
    while(l <= r) {
        ull mid = (l+r)/2;
        bool ok = true;
        ull u = 0;
        // cerr << "trying " << mid << endl;

        for(int i = 1; i <= n; i++) tmp[i] = 0;

        for(int i = 1; i <= n; i++) {
            tmp[i] += d[i];
            tmp[i] += tmp[i-1];
            // cerr << tmp[i] << endl;

            if(tmp[i] < mid) {
                int need = max(0ULL, mid-tmp[i]);
                u += need;
                // watch(u)
                if(max(u, (ull)need) > k) {
                    ok = false;
                    break;
                }

                tmp[i] += need;

                if(i+len <= n)
                tmp[i+len] -= need;

            }
        }

        // watch(u)

        cerr << l << " " << mid << " " << r << endl;
        watch(u)

        if(u > (ull)k) ok = false;
        if(ok) {
            ans = mid;
            l = mid+1;
        } else {
            cerr << "not ok" << endl;
            r = mid-1;
        }
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