// https://codeforces.com/contest/1303/problem/D

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

const int maxm = 100500;

int a[maxm];
int b[maxm];

void solve() {
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        b[i] = 0;
    }

    vector<int> cnt(100);
    int sum = 0;

    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        sum += a[i];
        while(a[i] != 1) {
            a[i] /= 2;
            b[i]++; 
        }

        cnt[b[i]]++;
    }

    if(sum < n) {
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    for(int i = 0; i <= 63; i++) {
        int x = (1LL<<i);
        if(n&x) {
            for(int j = i; j <= 63; j++) {
                if(cnt[j]) {
                    int ree = 0;
                    for(int k = j; k > i; k--) {
                        cnt[k]--;
                        cnt[k-1] += 2;
                        // ans++;
                        ree++;
                    }

                    cerr << i << " took " << ree << endl;
                    ans += ree;
                    break;
                }
            }
            cnt[i]--;
        }

        int hugs = cnt[i]/2;
        cnt[i] %= 2;
        cnt[i+1] += hugs;

        cerr << "pushing " << hugs << " from " << i << " to " << i+1 << endl;
    }

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

greedy/brute force

pull from highest factor

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
