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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> v;
    for(int i: vector<int>({n1, n2, n3})) {
        for(int j = 1; j <= i; j++) {
            int x;
            cin >> x;

            v.emplace_back(x);
        }
    }

    sort(all(v));

    int sum = 0;

    for(int i = 0; i < sz(v); i++) {
        if(i <= 1) sum -= v[i];
        else sum += v[i];
    }

    cout << sum << endl;
}

/*

brute force on which one is the last

try to create a really small number

GUESSFORCES


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?