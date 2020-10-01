// https://dmoj.ca/problem/wac5p1

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

const int maxn = 1500;

int a[maxn];
bool taken[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a+1, a+n+1, greater<int>());

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int last = INT_MAX;
        int price = -1;
        for(int j = 1; j <= n; j++) {
            if(!taken[j] and a[j] < last) {
                if(price == -1) {
                    price = a[j];
                    cerr << "setting price to " << price << endl;
                }

                cerr << "taking " << j << endl;
                taken[j] = true;
                last = a[j];
            }
        }

        if(last != INT_MAX) {
            cerr << "adding " << price << endl;
            ans += price;
        }
    }

    cout << ans << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
