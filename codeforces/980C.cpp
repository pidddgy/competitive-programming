// https://codeforces.com/contest/980/problem/C

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

int n, k;
int a[maxn];

// disjoint set, cardinality, key
int disj[maxn], car[maxn], key[maxn];

int findp(int v) {
    if(disj[v] == v) return v;
    else return disj[v] = findp(disj[v]);
}

void merge(int v, int v2) {
    if(v == v2) return;
    int p = findp(v), p2 = findp(v2);

    car[p] += car[p2];
    key[p] = min(key[p], key[p2]);
    disj[p2] = p;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxn; i++) {
        disj[i] = i;
        key[i] = i;
        car[i] = 1;
    }

    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < k; j++) {
            if(a[i]-j < 0) break;

            if(car[findp(a[i])] + car[findp(a[i]-j)] <= k) {
                merge(findp(a[i]), findp(a[i]-j));
            } else break;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << key[findp(a[i])] << " ";
    }
    cout << endl;
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
