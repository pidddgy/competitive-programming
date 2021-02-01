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

vector<int> cmp;
map<int, int> ac;

int p[maxn];
vector<pii> queries;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    

}

/*

lol lets pray that the shitter fucker is monotonic

keep track of the thing in a giant segtree w/ coordinate compression

bsearch on the partition point

bsearch on e v e r y t h i n g
calculate range of the two parts, sum

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
