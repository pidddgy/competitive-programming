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

const int maxn = 40;
int n, m;

int a[maxn];



signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    int f = n/2;

    set<int> S;
    for(int mask = 0; mask < (1<<f); mask++) {
        int sum = 0;
        for(int j = 1; j <= f; j++) {
            if(mask & (1 << (j-1))) {
                sum += a[j]%m;
                sum %= m;
            }
        }

        S.emplace(sum);
        cerr << "emplacing " << sum << endl;
    }
    S.emplace(0);

    int ans = 0;
    int s = n-f;
    for(int mask = 0; mask < (1<<s); mask++) {
        int sum = 0;
        for(int j = 1; j <= s; j++) {
            if(mask & (1 << (j-1))) {
                sum += a[f+j]%m;
                sum %= m;
            }
        }

        int rem = m-sum;

        auto it = S.lower_bound(rem);
        it--;

        ans = max(ans, ((*it)+sum)%m);
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
