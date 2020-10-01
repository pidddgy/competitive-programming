// https://codeforces.com/problemset/problem/546/D

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

const int maxn = 5e6+200;

int spf[maxn];

int facs(int num) {
    int ans = 0;

    while(num != 1) {
        num /= spf[num];
        ans++;
    }

    return ans;
}

int psa[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    spf[1] = 1; // undefined but hwatever
    for(int i = 2; i <= 5e6; i++) {
        spf[i] = i;
    }
    
    for(int i = 2; i <= 5e6; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j <= 5e6; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    for(int i = 2; i <= 5e6; i++) {
        psa[i] = facs(i)+psa[i-1];
    }

    int t;
    cin >> t;
    
    while(t--) {
        int a, b;
        cin >> a >> b;

        cout << psa[a]-psa[b] << endl;
    }
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
