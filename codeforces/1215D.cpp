// https://codeforces.com/contest/1215/problem/D    

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

int n;
string s;
vector<int> q;

pii a[3];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s;

    s = "."+s;

    for(int i = 1; i <= n/2; i++) {
        if(s[i] == '?') {
            a[1].fi++;
        } else {
            // sum1 += (s[i] - '0');
            a[1].se += (s[i] - '0');
        }
    }

    for(int i = (n/2)+1; i <= n; i++) {
        if(s[i] == '?') {
            a[2].fi++;
        } else {
            // sum1 += (s[i] - '0');
            a[2].se += (s[i] - '0');
        }
    }

    sort(a+1, a+3);

    int d = a[1].se-a[2].se;
    int C = a[2].fi-a[1].fi;

    watch(d)
    watch(C)

    if(d == (C/2)*9) {
        cout << "Bicarp" << endl;
    } else {
        cout << "Monocarp" << endl;
    }
}

/*

first person wants to imbalance the sums as much as possible, second person wants to balance

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
