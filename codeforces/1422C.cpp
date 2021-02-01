// https://codeforces.com/contest/1422/problem/C

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

const int MOD = (int)1e9+7;

int trng(int n) {
    return (n*(n+1))/2;
}

int mod(int num) {
    return (num+MOD)%MOD;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;

    int n = sz(s);

    s = "."+s;

    int p = 1;
    int sum = 0;
    int ans = 0;

    for(int i = n; i >= 1; i--) {
        int k = mod(mod(trng(i-1))*mod(p) + sum);
        ans = mod( ans + mod((s[i]-'0')*k));

        // how many ways are there to make p?
        sum = mod(sum+p*(n-i+1));
        p = mod(10*p);
    }

    cout << ans << endl;
}

/*

some places get "shifted down"

for each shfit think about how far each digit can be shifted

for each digit i there is i-shift possibilities where it gets shifted all the way to i-shift digit
for each digit i there is (n-i)-shift+1 possibilities where it stays the same
otherwise it doens't contribute to the sum at all

contribution to sum - how much does each digit contribute?
way to remove x from y are the same as ways to remove x+1 from y+1

observation: a digit can either become greater after shifting or nonexistent

new observation: digits dont become greater they just contribute or dont contribute

repeatedly add how many ways there are to get p
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
