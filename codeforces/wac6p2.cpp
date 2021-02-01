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

int n, m;

const int maxn = 200500;

int a[maxn];
int b[maxn];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int cur = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cur += a[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    for(int i = 0; i <= 1e6; i++) {
        if(i >= 1 and i <= m) {
            if(a[b[i]]) cur--;
            else cur++;

            a[b[i]] ^= 1;
        }

        if(cur <= i) {
            cout << i << endl;
            break;
        }
    }

}

/*

iterate over seconds
queue
make sure that number of lights on <= current seconds

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
