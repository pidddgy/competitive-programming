// https://codeforces.com/contest/584/problem/C

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

char isnt(char a, char b) {
    for(char x: string("abcdefghijklmnopqrstuvwxyz")) {
        if(x != a and x != b) return x;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    string s1, s2;
    cin >> s1 >> s2;

    string ans;
    for(int i = 0; i < n; i++) {
        ans += isnt(s1[i], s2[i]);
    }

    // watch(ans)

    deque<int> noteq, eq;
    for(int i = 0; i < n; i++) {
        if(s1[i] == s2[i]) {
            eq.emplace_back(i);
        } else {
            noteq.emplace_back(i);
        }
    }
    // differences between s1 to s3 and s2 to s3
    int diff = n;

    while(diff > t and eq.size()) {
        int i = eq.front(); eq.pop_front();
        // cerr << "making " << i << " equal" << endl;
        ans[i] = s1[i];
        assert(s1[i] == s2[i]);
        diff--;
    }

    while(diff > t and noteq.size() >= 2) {
        int i = noteq.front(); noteq.pop_front();
        int j = noteq.front(); noteq.pop_front();

        ans[i] = s1[i];
        ans[j] = s2[j];

        diff--;
    }

    if(diff == t) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }

}

/*

let d1 = s1 differences
let d2 = s2 differences

for every letter
    if s1[i] == s2[i],
        either add to both or do nothing
    else
        either add to both or add to d1 or add to d2

if s1[i] == s2[i], that is our only chance to not increment difference

otherwise either d1 or d2 gets incremented

start with maximized difference (d1 == d2 == n)
try to decrement as many 1s as possible by using indexes where s1[i] == s2[i]

then decrement 1s using pairs of the second kind
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
