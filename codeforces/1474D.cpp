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

const int maxn = 200500;

int n;
int a[maxn];
int tmp[maxn];

bool check() {
    for(int i = 0; i <= n+1; i++) {
        tmp[i] = a[i];
    }
    for(int i = 1; i <= n; i++) {
        cerr << tmp[i] << " ";
    }
    cerr << endl;

    for(int i = 1; i <= n; i++) {
        int mi = min(tmp[i], tmp[i+1]);
        tmp[i] -= mi;
        tmp[i+1] -= mi;
        cerr << "sub " << mi << " from " << i << endl;

        if(tmp[i]) {
            cerr << "failed on " << i << endl;
            for(int j = 1; j <= n; j++) {
                cerr << tmp[i] << " ";
            }
            cerr << endl;
            return false;
        }
    }

    return true;
}

void solve() {
    cin >> n;

    for(int i = 0; i <= n+1; i++) a[i] = tmp[i] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    bool ans = check();
    for(int i = 1; i <= n; i++) {
        int mi = min(a[i], a[i+1]);
        a[i] -= mi;
        a[i+1] -= mi;

        cerr << "subtract " << mi << " from " << i << ","<< i+1 << endl;
        if(a[i] > a[i-1]+a[i+1]) {
            if(i > 1) {
                cerr << "swapping " << i-1 << endl;
                swap(a[i], a[i-1]);
                ans |= check();
                swap(a[i], a[i-1]);
            }

            if(i-2 >= 1) {
                cerr << "swap " << i-2 << endl;
                swap(a[i-1], a[i-2]);
                ans |= check();
                swap(a[i-1], a[i-2]);
            }

            if(i < n) {
                swap(a[i], a[i+1]);
                ans |= check();
                swap(a[i], a[i+1]);
            }

            if(i+2 <= n) {
                cerr << "swapping " << i+1 << endl;
                swap(a[i+1], a[i+2]);
                ans |= check();
                swap(a[i+1], a[i+2]);
            }

            break;
        }
    }

    if(ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

check()

greedily remove

as soon as we hit any integer bigger than sum of two adjacent, try swapping those around

5
8 8 11 18 13 

pre[2] = 0
suf[3] = 


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
