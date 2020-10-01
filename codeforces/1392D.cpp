// https://codeforces.com/problemset/problem/1392/D

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
    int n;
    cin >> n;
    string s;
    cin >> s;

    deque<char> dq;
    for(char x: s) {
        dq.push_back(x);
    }

    for(int i = 1; i < 2*n; i++) {
        if(dq.front() == dq.back()) {
            dq.push_front(dq.back());
            dq.pop_back();
        }
    }

    s.clear();

    for(char x: dq) s += x;
    int run = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int l = ((i-1)+n)%n;
        int r = (i+1)%n;

        cerr << "on " << i << endl;

        int atk = 0;
        atk += s[l] == 'R';
        atk += s[r] == 'L';

        if(atk == 1) {
            if(s[l] == 'R' and s[i] != 'L') {
                run++;
                cerr << "incorrect strategy" << endl;
            } else if(s[r] == 'L' and s[i] != 'R') {
                run++;
                cerr << "incorrect strategy" << endl;
            } else {
                ans += (run+2)/3;
                run = 0;
            }
        } else {
            ans += (run+2)/3;
            run = 0;
        }
    }

    ans += (run+2)/3;
    
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

if a player is attacked by 0 then it doesnt matter

if a player is attacked by 1 then attack attacker

if attakced by 2 then it doesnt matter

separate into runs, (add run length + 2) / 3 to answer

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
