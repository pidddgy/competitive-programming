// https://codeforces.com/contest/1042/problem/C

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

const int maxn = 200500;
int n;
int a[maxn];

vector<pair<int, pii>> ans;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    // negative number w/ smallest absolute value
    pii sneg = pii(INT_MIN, -1);
    int neg = 0;
    vector<int> rem, other;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];

        if(a[i] < 0) {
            neg++;
            sneg = max(sneg, pii(a[i], i));
            other.emplace_back(i);
        } else if(a[i] == 0) {
            rem.emplace_back(i);
        } else {
            other.emplace_back(i);
        }
    } 

    if(neg&1) {
        rem.emplace_back(sneg.se);
        other.erase(remove(all(other), sneg.se));
    }

    for(int i = 0; i < sz(rem)-1; i++) {
        ans.emplace_back(1, pii(rem[i], rem[i+1]));
    }

    int op2 = -1;

    if(sz(rem) and sz(other)) op2 = rem.back();

    for(int i = 0; i < sz(other)-1; i++) {
        ans.emplace_back(1, pii(other[i], other[i+1]));
    }

    for(auto x: ans) {
        cout << x.fi << " " << x.se.fi << " " << x.se.se << endl;
    }

    if(op2 != -1) {
        cout << 2 << " " << op2 << endl;
    }
}

/*

join all the rem together

if there is an odd number of negatives, remove the one with lowest absolute value

if theres a zeros merge the removed negative number and the zero

remove that number
join the rest



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
