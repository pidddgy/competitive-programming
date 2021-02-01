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

const int maxn = 100500;

string s;
int pre[maxn], suf[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    s = "."+s;

    set<char> S;

    int cur = 0;
    for(int i = 1; i <= n; i++) {
        char x = s[i];
        while(sz(S) and *S.rbegin() > x) {
            auto y = *S.rbegin();
            S.erase(y);
        }

        if(!S.count(x)) {
            S.emplace(x);
            cur++;
        }

        pre[i] = cur;
    }

    S.clear();
    cur = 0;

    for(int i = n; i >= 1; i--) {
        char x = s[i];
        while(sz(S) and *S.rbegin() > x) {
            auto y = *S.rbegin();
            S.erase(y);
        }

        if(!S.count(x)) {
            S.emplace(x);
            cur++;
        }

        suf[i] = cur;
    }

    while(q--) {
        int l,r;
        cin >> l >> r;

        cout << pre[l-1] + suf[r+1] << endl;
    }
}

/*

prefix suffix

paint everything as a
if theres bpaint everything as b except for things intended to be b
if there is c paint everything as c except for anything intended to be a or b

use stack/set

for every new char x
    pop all chars greater than x

    if it is in the set continue
    else push and add one

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
