#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
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

int n;
int a[maxn];
int psa[maxn];

int query(int l, int r) {
    if(l>r) return 0;
    return psa[r]-psa[l-1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        psa[i] = psa[i-1]+a[i];
    }

    int ans = 1e18;
    for(int i = 2; i <= n-1; i++) {
        int l = i;
        int r = n-1;
        int lgood = n-1;

        // find leftmost with sum <= 1...i-1
        while(l <= r) {
            int mid = (l+r)/2;

            if(query(i, mid) <= query(mid+1, n)) {
                lgood = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        cerr << i << " " << lgood << endl;

        vector<int> v = {query(1, i-1), query(i, lgood), query(lgood+1, n)};
        sort(all(v));
        ans = min(ans, v[2]-v[0]);

        if(lgood+1 < n) {
            lgood++;
            v = {query(1, i-1), query(i, lgood), query(lgood+1, n)};
            sort(all(v));

            ans = min(ans, v[2]-v[0]);
            lgood--;
        }
        

        if(lgood-1 > i) lgood -= 1;
        v = {query(1, i-1), query(i, lgood), query(lgood+1, n)};
        sort(all(v));

        ans = min(ans, v[2]-v[0]);
    }

    cout << ans << endl;
}

/*

case: max is left, middle, right

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?