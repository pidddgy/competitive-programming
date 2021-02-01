// https://codeforces.com/contest/1238/problem/D

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

const int maxn = 300500;

int n;
string s;

int d = 0;

// count bad
int bad() {
    cerr << "aaaa" << endl;
    watch(s)
    vector<vector<int>> suf(2, vector<int>(maxn, 0));

    for(int i = n; i >= 1; i--) {
        suf[s[i]-'A'][i]++;
    }

    for(int i = 0; i <= 1; i++) {
        for(int j = n; j >= 1; j--) {
            suf[i][j] += suf[i][j+1];
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++) {
        int cur = s[i]-'A';
        char op;

        if(s[i] == 'A') op = 'B';
        else op = 'A';
        if(suf[cur^1][i+1]) {
            if(i < n and s[i+1] == op) {
                cerr << "double count on " << i << endl;
                d++;
            }
            res++;
        }
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s;

    s = "."+s;

    int ans = ((n-1)*n)/2;

    ans -= bad();
    // watch(bad())

    reverse(all(s));
    s.pop_back();
    s = "."+s;
    // watch(bad())

    ans -= bad();

    watch(d)
    ans += d/2;

    cout << ans << endl;
}

/*

each char has a minimum range so that it can be good

only consider palindromes of size 2 or 3
wlog:
ABA
BBA
ABB

fix l

all middle elements are guaranteed to be ok

only check valid l and r endpoints

an l...r pair works only if:
    - index of next letter eq. to s[l] is <= r
    - index of rightmost previous letter eq. to s[r] is >= l

bad would be AAAAAA...B or BBBB.A

next different is bad




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
