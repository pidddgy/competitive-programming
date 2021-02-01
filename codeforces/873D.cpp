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

const int maxn = 100500;
int a[maxn];

int n, k;
void unsort(int l, int r) {
    if(!k) return;
    if(l == r) return;

    int mid = (l+r+1)/2;

    swap(a[mid], a[mid-1]);

    k -= 2;
    unsort(l, mid-1);
    unsort(mid, r);
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    if(k % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) a[i] = i;
    
    k--;
    
    unsort(1, n);

    if(k) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
