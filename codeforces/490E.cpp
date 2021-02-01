// https://codeforces.com/contest/490/problem/E

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

const int maxn = 100500;
int n;

string a[maxn];

void no() {
    cout << "NO" << endl;
    exit(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        string orig = a[i];
        if(i == 1) {
            for(int j = 0; j < sz(a[i]); j++) {
                if(a[i][j] == '?') a[i][j] = '0';
            }
            if(a[i][0] == '0') a[i][0] = '1';
            continue;
        }

        if(sz(a[i]) < sz(a[i-1])) {
            no();
        }

        if(sz(a[i]) > sz(a[i-1])) {
            for(int j = 0; j < sz(a[i]); j++) {
                if(a[i][j] == '?') a[i][j] = '0';
            }
            if(a[i][0] == '0') a[i][0] = '1';
            continue;
        }

        bool f = false;
        int fin = LLONG_MAX;
        int len = sz(orig);

        for(int j = 0; j < len; j++) {
            // make j the one bigger
            bool ok = false;
            if((a[i][j] == '?' and a[i-1][j] != '9') or (a[i][j] != '?' and (a[i][j] > a[i-1][j]))) {
                if(a[i][j] == '?') {
                    char hugs = a[i-1][j]+1;
                    a[i][j] = a[i-1][j]+1;
                }
                ok = true;
                for(int k = j+1; k < len; k++) {
                    if(a[i][k] == '?')
                        a[i][k] = '0';
                }
            }

            if(ok) {
                fin = min(fin, stoll(a[i]));
            }

            if(orig[j] == '?') {
                a[i][j] = a[i-1][j];
            } else if(a[i-1][j] > a[i][j]) break;

            for(int k = j+1; k < len; k++) {
                if(orig[k] == '?') a[i][k] = '?';
            }
        }

        if(fin == LLONG_MAX) {
            no();
        }
        
        string ree = to_string(fin);
        while(sz(ree) < len) ree += '0';
        a[i] = ree;
    }

    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) {
        cout << a[i] << endl;
    }
}

/*

make each number as small as possible

28
102??3
2?9938
?039784
1296072
1525416
?766478
2059035
23?1571
2310?46
252?47?
315503?
3237088
3?251?7
3633448
3856?15
3946954
40605?1
460466?
4729070
49310?7
513?268
54?5?89
5?604?8
5?81991
6010704
6011689
6???053
6089577

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
