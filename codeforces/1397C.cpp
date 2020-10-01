// https://codeforces.com/contest/1397/problem/C

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

int a[maxn];
int n;
void print() {
    cerr << endl;
    cerr << "~~~" << endl;
    for(int i = 1; i <= n; i++) {
        cerr << a[i] << " ";
    }
    cerr << endl;
    cerr << "~~~" << endl;
    cerr << endl;
}
signed main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    if(n == 1) {
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << -a[1] << endl;
        cout << endl;
        return 0;
    }

    int len = n-1;

    print();
    cout << 1 << " " << len << endl;
    for(int i = 1; i <= n-1; i++) {
        cout << a[i]*len << " ";
        a[i] += a[i]*len;
        assert(a[i] % n == 0);
    }
    cout << endl;

    print();
    
    cout << 2 << " " << n << endl;

    for(int i = 2; i <= n; i++) {
        if(a[i] % n) {
            cout << a[i]*len << " ";
            a[i] += a[i]*len;
        } else {
            cout << 0 << " ";
        }

        assert(a[i] % n == 0);
    }
    cout << endl;

    cout << 1 << " " << n << endl;
    for(int i = 1; i <= n; i++) {
        cout << -a[i] << " ";
        assert((-a[i]) % n == 0);
    }
    cout << endl;
}

/*

7

1337 420 32 56 213 245

all elements have to be divisible by len to become 0




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
