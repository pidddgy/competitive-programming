// https://codeforces.com/contest/156/problem/B

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

string a[maxn];
int accused[maxn], defend[maxn];
int dt = 0;

// possible suspects
set<int> S;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        string ree;
        for(int j = 1; j < sz(a[i]); j++) {
            ree += a[i][j];
        }
        int b = stoi(ree);

        if(a[i][0] == '+') {
            accused[b]++;
        } else {
            defend[b]++;
            dt++;
        }
    }

    for(int i = 1; i <= n; i++) {
        int t = accused[i] + (dt-defend[i]);

        if(t == m) {
            S.emplace(i);
        }
    }

    // for(int x: S) {
    //     cerr << x << " ";
    // }
    // cerr << endl;

    for(int i = 1; i <= n; i++) {
        string ree;
        for(int j = 1; j < sz(a[i]); j++) {
            ree += a[i][j];
        }
        int b = stoi(ree);

        if(a[i][0] == '+') {
            if(S.count(b)) {
                if(sz(S) == 1) {
                    cout << "Truth" << endl;
                } else {
                    cout << "Not defined" << endl;
                }
            } else {
                cout << "Lie" << endl;
            }
        } else if(a[i][0] == '-') {
            if(S.count(b)) {
                if(sz(S) == 1) {
                    cout << "Lie" << endl;
                } else {
                    cout << "Not defined" << endl;
                }
            } else {
                cout << "Truth" << endl;
            }
        }
    }
}

/*

loop over each person, fixing this person as the one who committed the cirme
    check if m people are telling the truth
    if this person is the suspect:
        people that say this person committed are truthful
        people that say anyone other than this person are liars

        people that say this person didn't commit are liars
        people that say anyone other than this person didnt commit are truthful


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
