// https://codeforces.com/contest/926/problem/I

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

int n;
bool alarm[50][100];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        int h = 0;
        h += (s[0]-'0')*10;
        h += (s[1]-'0');

        int m = 0;
        m += (s[3]-'0')*10;
        m += (s[4]-'0');

        alarm[h][m] = true;
        cerr << "setting " << h << " " << m << endl;
    }    

    // max number of minutes
    int ma = 0;

    int cur = 0;
    for(int i = 0; i <= 1e6; i++) {
        int h = (i/60)%24;
        int m = i%60;

        if(alarm[h][m]) {
            cur = 0;
        } else {
            cur++;
        }

        ma = max(ma, cur);
    }

    watch(ma)

    int h = ma/60;
    int m = ma%60;

    if(h < 9) {
        cout << 0;
    }
    cout << h;
    cout << ":";
    if(m < 9) {
        cout << 0;
    }
    cout << m << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
