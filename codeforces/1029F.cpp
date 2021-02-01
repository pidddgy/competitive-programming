// https://codeforces.com/contest/1029/problem/F

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

int sum;

// prime factors
set<int> divisors(int num) {
    set<int> res;
    for(int i = 1; i*i <= num; i++) {
        if(num%i == 0) {
            res.emplace(i);
            res.emplace(num/i);
        }
    }

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // set<int> test = divisors((int)1e14);

    // for(int x: test) {
        // cerr << x << " ";
    // }
    // cerr << endl;

    int a, b;
    cin >> a >> b;

    if(a > b) swap(a, b);

    set<int> S = divisors(a), T = divisors(b);

    sum = a+b;

    int ans = LLONG_MAX;
    for(int i = 1; i*i <= sum; i++) {
        if((sum % i) == 0) {
            bool f = false;
            // j is the bigger one

            int j = sum/i;

            cerr << "trying " << i << " " << j << endl;

            // try using i
            // check if a can be put in rectangle inside another rectangle side lengths i, j
            // get biggest divisor of a <= i, that is x
            // other is y
            // check if y is <= j
            auto ptr = S.upper_bound(i);
            if(ptr != S.begin()) {
                ptr--;

                int x = (*ptr);
                int y = a/x;


                if(y <= j) {
                    cerr << x << " " << y << endl;
                    cerr << "can use a" << endl;
                    f = true;
                }
            }

            // check if we can use b
            ptr = T.upper_bound(j);
            if(ptr != T.begin()) {
                ptr--;

                int x = (*ptr);
                int y = b/x;

                if(y <= i) {
                    cerr << "can use b" << endl;
                    f = true;
                }
            }

            if(f) {
                cerr << "good" << endl;
                ans = min(ans, 2*(i+j));
            }
            cerr << endl;
        }
    }

    cout << ans << endl;
}

/*

a <= b

a[1] + a[2] + a[1] + a[2]
a[1] * a[2] = a+b

am-gm

we want the rectangle to be as square as possible

5 7


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
