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

bool pal(string s) {
    string rev = s;
    reverse(all(s));

    return rev==s;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = sz(s);
    s = "."+s;

    set<char> S;
    for(int i = 1; i <= n/2; i++) {
        S.emplace(s[i]);
        S.emplace(s[n-i+1]);
    }

    watch(sz(S))
    if(sz(S) == 1 or n == 1) {
        cout << "Impossible" << endl;
        return 0;
    }

    int ans = 2;

    string add = "";
    for(int i = 1; i <= n-1; i++) {
        int rem = n-i;
        add += s[i];

        string cur = s.substr(i+1, rem);
        cerr << add << " " << cur << endl;
        cur += add;
        
        if(pal(cur) and cur != s.substr(1, n)) {
            cerr << "split at " << i << " for " << cur << endl;
            ans = 1;
        }
    }

    cout << ans << endl;


}

/*

all same letter (not including middle if odd) = impossible
if length is even answer = 1

aaabcbaaa
baaacaaab

we can cut at first different letter for cut = 2

abba abba

acbca

aabaa

abcba

abcbaabcba
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
