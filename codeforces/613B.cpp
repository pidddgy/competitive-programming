// https://codeforces.com/contest/613/problem/B

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
int n, A, cf, cm, m;

pii a[maxn];
int ans[maxn];
int psa[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> A >> cf >> cm >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi;
        a[i].se = i;
        ans[i] = a[i].fi;
    }

    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i++) {
        psa[i] = psa[i-1]+a[i].fi;
    }

    pii best = {0, 0};
    int sum = 0;
    int ree = 0;
    for(int i = n+1; i >= 1; i--) {
        sum += a[i].fi;
        int cost = (n-i+1)*A - sum;

        if(cost > m) break;
        watch(cost)

        int rem = m-cost;
        int l = 1, r = A;
        int lgood = 0;
        int ind = 0;
        cerr << i << endl;
        watch(cost)
        while(l <= r) {
            int mid = (l+r)/2;
            cerr << "trying " << mid << endl;

            int l1 = 1, r1 = i-1;
            int lgood2 = 0;
            while(l1 <= r1) {
                int mid2 = (l1+r1)/2;

                if(a[mid2].fi > mid) {
                    r1 = mid2-1;
                } else {
                    lgood2 = mid2;
                    l1 = mid2+1;
                }
            }

            watch(lgood2)

            int cost2 = mid*lgood2 - psa[lgood2];
            watch(psa[lgood])

            if(cost + cost2 <= m) {
                lgood = mid;
                ind = lgood2;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        cerr << "can make min " << lgood << endl;
        int loc = (n-i+1)*cf + lgood*cm;
        l = ind+1;
        r = i-1;
        
        if(loc > ree) {
            ree = loc;
            best = {n-i+1, lgood};
        }
    }

    cerr << best.fi << " " << best.se << endl;
    for(int i = 0; i < best.fi; i++) {
        ans[a[n-i].se] = A;
    }

    cout << ree << endl;
    for(int i = 1; i <= n; i++) {
        ans[i] = max(ans[i], best.se);

        cout << ans[i] << " ";
    }
    cout << endl;
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
