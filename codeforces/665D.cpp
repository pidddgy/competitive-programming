// https://codeforces.com/contest/665/problem/D

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

const int maxn = 1005;
const int maxv = (int)1e6+5;

int n;
int a[maxn];
bool prime[maxv*2];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 2e6; i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;

    for(int i = 2; i*i <= 2e6; i++) {
        if(prime[i]) {
            for(int j = i*i; j <= 2e6; j += i) {
                prime[j] = false;
            }
        }
    }

    // watch(prime[131])
    // watch(prime[242])
    // watch(prime[97])
    // watch(prime[69])
    // watch(prime[420])

    cin >> n;
    int cnt1 = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt1 += (a[i]==1);
    }

    vector<int> ans1;
    vector<int> ans2;

    if(cnt1) {
        int add = -1;
        for(int j = 1; j <= n; j++) {
            if(a[j] != 1 and prime[a[j]+1]) {
                ans1.emplace_back(a[j]);
                break;
            }
        }

        for(int i = 1; i <= cnt1; i++) {
            ans1.emplace_back(1);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;

            cerr << "hiii" << endl;
            if(prime[a[i]+a[j]]) {
                ans2.emplace_back(a[i]);
                ans2.emplace_back(a[j]);
            }

            if(sz(ans2)) break;
        }
        if(sz(ans2)) break;   
    }

    if(max(sz(ans1), sz(ans2)) == 0)  {
        cout << 1 << endl;
        cout << a[1] << endl;
    } else {
        if(sz(ans1) > sz(ans2)) {
            cout << sz(ans1) << endl;
            for(int x: ans1) {
                cout << x << " ";
            }
            cout << endl;
        } else {
            cout << sz(ans2) << endl;
            for(int x: ans2) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
}

/*

observations:
    - you cannot have more than one even number
    - you cannot have more than one odd number (exception is 1, we can have any number of those)

handle edge case with 1



*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
