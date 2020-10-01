// https://codeforces.com/contest/817/problem/D

#include <bits/stdc++.h>
using namespace std;
// #define cerr cout
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

const int maxn = (int)1e6+500;
int n;
int a[maxn];

// on left, rightmost element greater than i
int l[maxn], r[maxn];

// for minimum, we want left boundary to be <= cur and right boundary to be < cur
// for maximum we want left boundary to be >= cur and right boundary to be > cur
// exclude boundaries
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    stack<int> S;
    // first calculate min
    for(int i = 1; i <= n; i++) {
        while(sz(S) and a[S.top()] > a[i]) {
            S.pop();
        }

        if(sz(S)) l[i] = S.top();
        else l[i] = 0;

        S.push(i);
    }

    while(sz(S)) S.pop();

    for(int i = n; i >= 1; i--) {
        while(sz(S) and a[S.top()] >= a[i]) {
            S.pop();
        }

        if(sz(S)) r[i] = S.top();
        else r[i] = n+1;

        S.push(i);
    }

    for(int i = 1; i <= n; i++) {
        cerr << "min range for " << i << " is " << l[i] << " " << r[i] << endl;
        ans -= (i-l[i]) * (r[i]-i) * a[i];
    }

    while(sz(S)) S.pop();
    for(int i = 1; i <= n; i++) {
        while(sz(S) and a[S.top()] < a[i]) {
            S.pop();
        }

        if(sz(S)) l[i] = S.top();
        else l[i] = 0;

        S.push(i);
    }

    while(sz(S)) S.pop();
    for(int i = n; i >= 1; i--) {
        while(sz(S) and a[S.top()] <= a[i]) {
            S.pop();
        }

        if(sz(S)) r[i] = S.top();
        else r[i] = n+1;

        S.push(i);
    }

    for(int i = 1; i <= n; i++) {
        cerr << "max range for " << i << " is " << l[i] << " " << r[i] << endl;
        ans += (i-l[i]) * (r[i]-i) * a[i];
    }

    cout << ans << endl;
}

/*

for min

for every element
    we want to know how many subarrays could have this element as min. for each element on the left we store the rightmost element that is less than this. on the right we store the leftmost element less than current.

    to get the left/right elements:
        store a set of values and indexes

        when traversing a new element, push it onto a set and delete all elements with greater value

        to query, call lower_bound(val) and decrement the pointer (check if pointer is begin() before decrementing)

for max

for every element
    on the left, store rightmost element that is more than current
    on the right, store leftmost element that is more than current

    to get the left/right elements:
        store a set of values and indexes

        when traversing a new element, push it onto a set and delete all elements with smaller value

        to query, call lower_bound(val) and decrement the pointer (check if pointer is begin() before decrementing)

ok nvm segtree time im done with this shit

remember that when bsearching on left we make it strictly greater/less than and on right we do <= or >=
imagine that if a subarray has a duplicate min, we only take the left element

8
1 3 2 4 18 29 3 2

4
1 3 2 27

5
1 2 2 2 1
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?