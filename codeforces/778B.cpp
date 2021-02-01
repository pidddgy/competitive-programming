// https://codeforces.com/contest/778/problem/B

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

const int maxn = 5050;
const int maxm = 1005;

string l[maxn];
string op[maxn];

char mi[maxm], ma[maxm];

// ith element, jth bit, set jth bit to 0 or 1 in question mark
int a[maxn][maxm][2];
map<string, int> ind;

bool bitstr(string &s) {
    for(char x: s) {
        if(x != '0' and x != '1') return false;
    }
    return true;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;  

    for(int j = 0; j < m; j++) {
        a[5003][j][0] = 0;
        a[5003][j][1] = 1;
    }

    ind["?"] = 5003;

    for(int i = 1; i <= n; i++) {
        string var;
        cin >> var;

        ind[var] = i;

        string _;
        // ignore :=
        cin >> _;

        cin >> _;
        if(bitstr(_)) {
            for(int j = 0; j < m; j++) {
                a[i][j][0] = a[i][j][1] = _[j]-'0';
            }
            continue;
        }

        int t1 = 5003, t2 = 5003;
        string op, r;
        cin >> op >> r;

        t1 = ind[_];
        t2 = ind[r];

       for(int j = 0; j < m; j++) {
            for(int k = 0; k <= 1; k++) {
                if(op == "OR") {
                    a[i][j][k] = a[t1][j][k] | a[t2][j][k];
                } else if(op == "AND") {
                    a[i][j][k] = a[t1][j][k] & a[t2][j][k];
                } else if(op == "XOR") {
                    a[i][j][k] = a[t1][j][k] ^ a[t2][j][k];
                }
            }
        }
    }    

    for(int j = 0; j < m; j++) {
        vector<int> cnt(2);
        for(int i = 1; i <= n; i++) {
            for(int k = 0; k <= 1; k++) {
                cnt[k] += a[i][j][k];
            }
        }

        for(int k = 1; k >= 0; k--) {
            if(cnt[k] == min(cnt[0], cnt[1])) {
                mi[j] = k+'0';
            }

            if(cnt[k] == max(cnt[0], cnt[1])) {
                ma[j] = k+'0';
            }
        }
    }

    for(int j = 0; j < m; j++) {
        cout << mi[j];
    }
    cout << endl;

    for(int j = 0; j < m; j++) {
        cout << ma[j];
    }
    cout << endl;
}

/*

solve for each bit

check if 0/1 makes it better or worse

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?