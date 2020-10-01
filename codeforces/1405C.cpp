// https://codeforces.com/contest/1405/problem/C

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

const int maxn = 300500;
string s;
int psa[3][maxn];

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string ans = "YES";
    for(int i = 0; i < k; i++) {
        set<char> S;
        for(int j = i; j < n; j += k) {
            S.emplace(s[j]);
        }

        if(S.count('?')) S.erase('?');

        if(sz(S) > 1) ans = "NO";

        if(*S.begin() != '?')
        for(int j = i; j < n; j += k) {
            s[j] = *S.begin();
        }
    }


    watch(s)

    int z = 0, o = 0;
    for(int i = 0; i < k; i++) {
        if(s[i] == '0') o++;
        else if(s[i] == '1') z++;
    }

    if(z > k/2 or o > k/2) ans = "NO";

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

greedily replace question marks with whatever is needed

check if wrong at any point

if its not wrong then it can be done

if we have any string of length k filled out we can get the rest
if we have any string of length k-1 filled out we can get the string of length k
if we have any string of length k-2 filled out

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
