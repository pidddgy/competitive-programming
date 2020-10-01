// https://codeforces.com/contest/847/problem/C

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

const int maxn = (int)3e5+5;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    if(k > (maxn*(maxn+1))/2) {
        cout << "Impossible" << endl;
        return 0;
    }

    int cur = 0, sum = 0, used = 0;

    vector<int> v;
    while(sum < k and used < n) {
        while(sum+cur > k) cur--;

        v.emplace_back(cur);
        sum += cur;
        cur++;
        used++;
    }

    if(sum != k) {
        cout << "Impossible" << endl;
        return 0;
    }
    
    string ans;
    cur = 0;
    for(int i = 0; i < sz(v); i++) {
        if(i > 0) {
            for(int j = 1; j <= max(0LL, v[i-1]-v[i]+1); j++) {
                ans += ')';
            }
        }
        ans += '(';

    }

    if(sz(v))
    for(int i = 1; i <= v.back()+1; i++) {
        ans += ')';
    }

    for(int i = 1; i <= n-used; i++) {
        ans += "()";
    }

    cout << ans << endl;
}

/*

represent k as sum of a sequence of numbers

in this sequence we can go up by 1, or go down by any non-negative amount

if it is bigger than the 3e5th triangular number then it is not possible
probably fine tm because something something triangular numbers

( ( ( ( ( ( ( ( (())?)))))))

( ( ( ( ( ( ( ( ( ) )(?)))))))
0 1 2 3 4 5 6 7 8 

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
