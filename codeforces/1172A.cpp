// https://codeforces.com/contest/1172/problem/A

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

const int maxn = 200500;

int n;
int a[maxn], b[maxn];
int p[maxn];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] != 0) {
            p[a[i]] = -1;
        }
    }

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        p[b[i]] = i;
    }

    int ans = LLONG_MAX;

    int ma = 0;
    for(int i = 1; i <= n; i++) {
        if(p[i] != -1) {
            cerr << i << " is " << p[i]+1-i << endl;
            ma = max(ma, p[i]+1-i);
        }
    }

    ans = ma+n;

    // check if we can get a solution without putting 0s and playing 1..n over again

    int ind = -1;
    for(int i = 1; i <= n; i++) {
        if(b[i] == 1) ind = i;
    }

    if(ind != -1) {
        cerr << "a" << endl;
        bool ok = true;
        int need = 1;


        for(int i = ind; i <= n; i++) {
            if(b[i] != need) ok = false;

            cerr << "on " << i << ", need " << need << endl;
            need++;
        }

        for(int i = 1; i < ind; i++) {
            if(p[need] != -1) {
                ok = false;
            }

            cerr << "on " << i << ", need " << need << endl;

            p[b[i]] = -1;
            need++;
        }

        if(ok) ans = min(ans, ind-1);
    }

    cout << ans << endl;
}

/*

no matter what we need to push 1 to the edge

upper bound: 2*n

guess: never insert 0

we either have to insert 0s or we dont at all (cyclic shift)
if we ahve to insert a 0 then we have to play all the cards again to push the 0 out

we would like to get card number i in i-1 moves
we will get card number i in p[i] moves

p[i] - x = i-1
p[i] = i-1 + x
p[i]-i = -1+x

p[i]+1-i = x

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
