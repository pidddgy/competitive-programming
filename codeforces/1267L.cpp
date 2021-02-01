// https://codeforces.com/contest/1267/problem/L

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

const int maxn = 1050;

int n, l, k;
map<char, int> cnt;
string ans[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, l, k;
    cin >> n >> l >> k;

    string s;
    cin >> s;

    for(char x: s) cnt[x]++;

    int same = k;
    char cur = 'a';

    for(int i = 1; i <= l; i++) {
        for(int j = k-same+1; j <= k; j++) {
            while(!cnt[cur]) cur++;

            ans[j] += cur;
            cnt[cur]--;
        }

        int j = k;
        while(j >= 1 and sz(ans[j]) == i and ans[j].back() == cur) {
            j--;
        }

        same = k-j;
    }

    for(int i = 1; i <= n; i++) {
        while(sz(ans[i]) < l) {
            while(!cnt[cur]) cur++;

            ans[i] += cur;
            cnt[cur]--;
        }
    }

    sort(ans+1, ans+n+1);
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }


}

/*

keep track of first string with same prefix, repeatedly put smallest letters at that index and go to the right

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
