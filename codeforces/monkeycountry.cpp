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

const int maxn = (int)1e7+500;
const int MOD = (int)1e9+7;
int n, p, q;

int a[maxn];
int ans[maxn];
int d[maxn];
int elapsed = 0;

int mod(int num) {
    return (num+MOD)%MOD;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }    

    int cur = 0;
    for(int i = 1; i <= n; i++) {
        cur += d[i];
        a[i] += cur;

        int k = n-i+1;
        int gain = ((k*p)/q);        
        gain = mod(gain);

        d[n-gain+1] += mod(2*a[i]);
        d[i+1] -= a[i];

        ans[i] = mod(a[i]);
    }

    for(int i = 1; i <= n; i++) {
        ans[i] += ans[i-1];
        ans[i] = mod(ans[i]);
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
