// https://codeforces.com/contest/220/problem/B

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

const int maxn = 100500;

int a[maxn], cnt[maxn], psa[maxn];
int l[maxn], r[maxn], ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] <= 1e5) {
            cnt[a[i]]++;
        }
    }

    vector<int> valid;
    for(int i = 1; i <= 1e5; i++) {
        if(cnt[i] >= i) valid.emplace_back(i);
    }

    for(int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
    }


    for(int x: valid) {
        for(int i = 0; i < maxn; i++) {
            psa[i] = 0;
        }

        for(int i = 1; i <= n; i++) {
            if(a[i] == x) psa[i]++;

            psa[i] += psa[i-1];
        }

        for(int i = 1; i <= m; i++) {
            if(psa[r[i]]-psa[l[i]-1] == x) {
                ans[i]++;
            }
        }
    }

    for(int i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
}

/*

not many possible distinct numbers (triangular number)

there are max 450ish numbers that will ever work

for each number
    calculate psa

    loop over all queries

print answer




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
