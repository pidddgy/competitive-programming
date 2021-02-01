// https://codeforces.com/contest/1119/problem/D

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

int n, q;
int s[maxn], ans[maxn], a[maxn];
pii query[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    cin >> q;
    for(int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;

        query[i] = pii(r-l+1, i);
    }    

    sort(s+1, s+n+1);
    sort(query+1, query+q+1);

    for(int i = 1; i <= n-1; i++) {
        a[i] = s[i+1]-s[i];
    }
    a[n] = LLONG_MAX;

    sort(a+1, a+n+1);

    int cur = 1;
    int sum = 0;
    int rem = 0;
    for(int i = 1; i <= q; i++) {
        while(a[cur] < query[i].fi) {
            sum += a[cur]-query[i-1].fi;
            cur++;
            rem++;
        }

        sum += (n-rem)*(query[i].fi-query[i-1].fi);
        ans[query[i].se] = sum;
    }

    for(int i = 1; i <= q; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

/*

sort s[i]

realize that each element is useless when it hits the next element

sort elements by when they begin to contribute nothing

do offline query

for i in lengths
    remove all that become useless, adding however many they get in before they contribute nothing
    add 1 for every other element that still contributes

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
