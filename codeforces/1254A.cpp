// https://codeforces.com/contest/1254/problem/A

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

const int maxn = 105;

string chars;
char a[maxn][maxn], ans[maxn][maxn];

void solve() {
    chars.clear();
    for(int i = 0; i <= 9; i++) {
        char emp = '0'+i;
        chars += emp;
    }

    for(int i = 0; i < 26; i++) {
        char emp = 'a'+i;
        chars += emp;

        emp = 'A'+i;
        chars += emp;
    }

    int r, c, k;
    cin >> r >> c >> k;

    int totrice = 0;
    for(int i = 1; i <= r; i++) {
        string s;
        cin >> s;

        for(int j = 1; j <= c; j++) {
            a[i][j] = s[j-1];
            if(a[i][j] == 'R') totrice++;
        }
    }

    int per = totrice/k;
    int more = totrice%k; // how many rabbits get +1

    int d = 1, rice = 0, cur = 1, currabbit = 1;
    for(int i = 1; i <= r; i++) {
        while(cur >= 1 and cur <= c) {
            cerr << i << " " << cur << endl;
            ans[i][cur] = chars.back();
            if(a[i][cur] == 'R') {
                cerr << "adding" << endl;
                rice++;
            }

            int need = per;
            if(currabbit <= more) need++;

            if(rice == need) {
                cerr << "hit " << need << endl;

                if(currabbit != k) {
                    chars.pop_back();
                }
                
                currabbit++;
                rice = 0;
            }

            cur += d;
        }

        d *= -1;
        cur += d;
    }

    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
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
