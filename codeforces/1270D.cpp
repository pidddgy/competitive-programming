#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
// #define endl '\n'
#define ld long double
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

signed main() {
    int n, k;
    cin >> n >> k;

    vector<int> v;
    for(int i = 1; i <= k+1; i++) {
        cout << "? ";
        for(int j = 1; j <= k+1; j++) {
            if(i != j) cout << j << " ";
        }
        cout << endl;

        int x, y;
        cin >> x >> y;

        v.push_back(y);
    }

    int ma = *max_element(all(v));

    cout << "! " << count(all(v), ma) << endl;
}

/*

get any k-1 elements known
we can always know n-k+1 elements
in some cases elements will be impossible to find out

the worst case is when k = n-1
we would know 2 elements

we just need to find the relative order




*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
