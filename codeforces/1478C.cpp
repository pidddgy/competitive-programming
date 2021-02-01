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
    int n;
    cin >> n;

    vector<int> v;
    for(int i = 1; i <= 2*n; i++) {
        int x;
        cin >> x;

        v.emplace_back(x);
    }

    sort(all(v));
    reverse(all(v));

    string ans = "YES";
    int l = 0;
    int shit = 0;
    set<int> S;
    for(int i = 0; i < sz(v); i += 2) {

    if (v[i]-l <= 0) ans = "NO";
    if(v[i] != v[i+1]) ans = "NO";
        if((v[i]-l) % (2*(n-shit))) {
            ans = "NO";
            cerr << "failed on " << i << endl;
        }
        
        // watch(l)
        // watch(v[i]-l)
        // watch(n-shit)
        int b = (v[i]-l) / (2*(n-shit));

        watch(b)
        l += 2*b;

        if(b == 0) {
            ans = "NO";
            cerr << "h" << endl;
        }

        S.emplace(b);
        S.emplace(-b);
        cerr << endl;
        shit++;
    }

    if(sz(S) != 2*n) ans = "NO";

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

sorted differences
range is ma-mi so first difference is ma-mi * n
let b = biggest element

2*b * n = d

b = d/2/n

second difference is 2*b * n-1 + ma-mi

2*b * n-1 + ma-mi = d
2*b * n-1 + last range = d 
b = d - last range / (n-1) / 2


n is 6
-20 -18 -13 -12 -10 -5 5 10 12 13 18 20 
-20 makes 240
-18 makes 220
-13 makes 180
-12 makes 174
-10 makes 166
-5 makes 156

4
144 144 138 138 122 122 120 120 
-18 -17 -13 -12 12 13 17 18 


n is 4
-19 -13 -12 -1 1 12 13 19 
-19 makes 152
-13 makes 116
-12 makes 112
-1 makes 90
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?