// https://codeforces.com/contest/1005/problem/E1

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

int a[maxn];
map<int, int> cnt[2];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int ind;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == m) ind = i;
    }

    int cur = 0;
    for(int i = ind; i >= 1; i--) {
        if(a[i] < m) cur--;
        else if(a[i] > m) cur++;

        cnt[(ind-i)%2][cur]++;
    }

    cur = 0;
    int ans = 0;
    for(int i = ind; i <= n; i++) {
        if(a[i] < m) cur--;
        else if(a[i] > m) cur++;

        cerr << "on " << i << endl;
        watch(cur)
        if((i-ind) % 2) {
            cerr << "r is odd" << endl;
            ans += cnt[0][-cur+1];
            ans += cnt[1][-cur];
            watch(cnt[0][-cur+1])
            watch(cnt[1][-cur])
            watch(cnt[0][-cur+1]+cnt[1][cur])
        } else {
            cerr << "r even " << endl;
            ans += cnt[0][-cur];
            ans += cnt[1][-cur+1];
            watch(cnt[0][-cur])
            watch(cnt[1][-cur+1])
            cerr << "looking for " << -cur+1 << endl;
            watch(cnt[0][-cur] + cnt[1][-cur+1])
        }
        cerr << endl;
    }

    cout << ans << endl;
}

/*

elements are either less than or more
less should equal more

for i in ind...n 
    calculate number of less/more we need to balance out
    let cur

    if r is odd
        if l is even we need (-cur)+1
        if l is odd we need -cur
    if r is even
        if l is even we need (-cur)
        if l is odd we need (-cur)+1
    


s s 3 4 5 b

 s s s m b b b b
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
