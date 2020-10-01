// https://codeforces.com/contest/222/problem/C

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
const int maxv = (int)1e7+500;

int spf[maxv];

int a[maxn], b[maxn];

// how much to remove
int pcnt[2][maxv];
vector<int> primes;

void upd(int num, int ind) {
    while(num != 1) {
        pcnt[ind][spf[num]]++;
        num /= spf[num];
    }
}

int query(int num, int ind) {
    int ret = num;
    while(num != 1) {
        if(pcnt[ind][spf[num]]) {
            ret /= spf[num];
            pcnt[ind][spf[num]]--;
        }
        num /= spf[num];
    }

    return ret;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < maxv; i++) {
        spf[i] = i;
    }    

    for(int i = 2; i <= 1e7; i++) {
        if(spf[i] == i) {
            primes.emplace_back(i);
            for(int j = i*i; j <= 1e7; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        upd(a[i], 0);
    }

    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        upd(b[i], 1);
    }

    for(int i = 1; i <= 1e7; i++) {
        int rem = min(pcnt[0][i], pcnt[1][i]);
        pcnt[0][i] = pcnt[1][i] = rem;
    }

    cout << n << " " << m << endl;
    for(int i = 1; i <= n; i++) {
        cout << query(a[i], 0) << " ";
    }
    cout << endl;

    for(int i = 1; i <= m; i++) {
        cout << query(b[i], 1) << " ";
    }
    cout << endl;
}

/*

there are roughly 6 * 10^5 primes under 1e7

for each number use smallest prime factor technique to factorize in logn

maintain counts of each prime on top/bottom

for each prime subtract smaller count of prime

push into two sets, compress as much as possible

8388608
10000000

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
