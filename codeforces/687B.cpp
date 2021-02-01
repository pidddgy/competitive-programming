// https://codeforces.com/contest/687/problem/B

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

const int maxn = (int)1e6+50;

int n, k;
int a[maxn];

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int spf[maxn], cnt[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i <= 1e6; i++) spf[i] = i;
    spf[1] = LLONG_MAX;
    for(int i = 2; i <= 1e6; i++) {
        if(spf[i] == i) {
            for(int j = i*i; j <= 1e6; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        while(a[i] > 1) {
            int f = spf[a[i]];
            int amt = 0;

            while(a[i] % f == 0) {
                a[i] /= f;
                amt++;
            }

            cnt[f] = max(cnt[f], amt);
        }
    }
    
    bool divis = true;
    while(k > 1) {
        int f = spf[k];
        int amt = 0;

        while(k % f == 0) {
            k /= f;
            amt++;
        }

        if(amt > cnt[f]) divis = false;
    }

    if(divis) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
}

/*

if lcm divisible by k then yes
else no

we look for case where there is no

find any x1, x2 such that is lcm is divisible by x1-x2 and x1-x2 is not divisible by k

both x1 and x2 has to be divisible by lcm and if they arent we can replace them so that they are, thus we use factors of lcm so if lcm is divisible by k then there is no solution

you can use a-b == 0 to check if they have equal parity


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
