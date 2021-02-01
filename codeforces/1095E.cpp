// https://codeforces.com/contest/1095/problem/E    

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

const int maxn = (int)1e6+50;

int psa[maxn];

// prefix/suffix min
int pre[maxn];
int suf[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    s = "."+s;

    for(int i = 1; i <= n; i++) {
        if(s[i] == '(') psa[i]++;
        else psa[i]--;

        psa[i] += psa[i-1];
    }

    for(int i = 1; i <= n; i++) {
        cerr << psa[i] << " ";
    }
    cerr << endl;

    suf[n] = psa[n];
    for(int i = n-1; i >= 1; i--) {
        suf[i] = min(psa[i], suf[i+1]);
    }

    pre[0] = LLONG_MAX;
    pre[1] = psa[1];
    for(int i = 2; i <= n; i++) {
        pre[i] = min(psa[i], pre[i-1]);
    }

    int ans = 0;
    if(psa[n] == 2) {
        for(int i = n; i >= 1; i--) {
            if(s[i] == '(' and suf[i]-2 >= 0 and pre[i-1] >= 0) ans++;
        }
    } else if(psa[n] == -2) {
        for(int i = n; i >= 1; i--) {
            if(s[i] == ')' and suf[i]+2 >= 0 and pre[i-1] >= 0) {
                cerr << i << " is good" << endl;
                ans++;
            }
        }
    }

    cout << ans << endl;
}

/*

if already balanced ans = 0

consider psa

a bracket is bad if any prefix sum is negative or psa[n] != 

get sum

if sum == 0 ans = 0
if sum is 2 then we change any ) to ( except 

(((())
if sum is -2 then we change

4
)())

psa = {-1, 0, -1, -2}

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
