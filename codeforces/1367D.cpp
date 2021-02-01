// https://codeforces.com/problemset/problem/1367/D

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

const int maxm = 70;

int b[maxm];
char ans[maxm];

void solve() {
    string s;
    cin >> s;
    map<char, int> cnt;
    for(char x: s) cnt[x]++;

    int m;
    cin >> m;

    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        ans[i] = '?';
    }

    char cur = 'z';

    for(int i = 1; i <= 26; i++) {
        vector<int> inds;
        for(int j = 1; j <= m; j++) {
            if(ans[j] == '?' and b[j] == 0) {
                inds.emplace_back(j);
            }
        }

        if(inds.empty()) continue;
        
        while(cnt[cur] < sz(inds)) cur--;

        cerr << "using " << cur << endl;

        for(int j: inds) {
            ans[j] = cur;
            cnt[cur]--;
            for(int k = 1; k <= m; k++) {
                if(b[k] != 0) {
                    b[k] -= abs(j-k);
                }
            }
        }

        if(cur > 'a')
        cur--;
    }

    for(int i = 1; i <= m; i++) {
        cout << ans[i];
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> q;

    while(q--) {
        solve();
    }
}

/*
12 500 

if b[j] == 0 then no others can impact it
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
