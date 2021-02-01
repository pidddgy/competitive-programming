// https://codeforces.com/contest/998/problem/B

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

int n, b;
const int maxn = 105;
int a[maxn], psa[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> b;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        if(a[i] % 2 == 0) {
            psa[i]++;
        } else {
            psa[i]--;
        }
        psa[i] += psa[i-1];
    }   

    vector<int> cuts;
    for(int i = 1; i <= n-1; i++) {
        if(psa[i] == 0) {
            cuts.emplace_back(abs(a[i+1]-a[i]));
        }
    }

    sort(all(cuts));

    int ans = 0;
    for(int x: cuts) {
        if(b >= x) {
            b -= x;
            ans++;
        }
    }

    cout << ans << endl;
}

/*

brute force over number of odd/even

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
