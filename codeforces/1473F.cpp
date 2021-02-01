#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

int n;
int a[3005], b[3005];
bool vis[3005];
bool S[3005];


vector<int> f[3005];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    clock_t z = clock();


    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            if(a[i] % a[j] == 0) f[i].emplace_back(j);
        }
    }

    ll ans = 0;

    int shit = 0;
    
    for(;;) {
        for(int i = 1; i <= n; i++) {
            if(vis[i]) continue;

            // will adding this element help us?
            ll add = 0;
            for(int j: f[i]) {
                if(!S[j]) {
                    add += b[j];
                }
            }

            if(add >= 1) {
                vis[i] = true;
                ans += add;

                for(int j: f[i]) {
                    S[j] = true;
                }
            }
        }
        shit++;

        if(shit % 5 == 0) {
            if(((clock()-z) / (double)CLOCKS_PER_SEC) > 3.8) break;
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
