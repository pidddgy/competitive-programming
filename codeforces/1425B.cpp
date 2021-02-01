// https://codeforces.com/contest/1452/problem/B

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

const int maxn = 100500;

int a[maxn];

// ceililnv division
int ce(int a, int b) {
    return (a+b-1) / b;
}
void solve() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int sum = 0;
    int ma = 0;
    for(int i = 1; i <= n; i++) {
        sum += a[i];
        ma = max(ma, a[i]);
    }

    int x = sum;

    if(sum % (n-1))
        x += ((n-1)-(sum%(n-1)));

    // watch(sum);
    // watch(n-1)
    // watch(x)

    int ree = max(ma*(n-1), x);

    cout << ree-sum << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) solve();
}

/*

sum needs to be divisible by n-1

we make all elements max(sum/n-1, ma element*n-1)

worst case is when we take min


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
