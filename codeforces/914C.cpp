// https://codeforces.com/contest/914/problem/C

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
#define all(x) (x).begin(), (x).end()

void solve() {
    
}


const int maxn = 2500;
const int MOD = 1000000007;

// If we need i operations, what number of bits are eligible
set<int> nums[maxn];
int choose[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    choose[0][0] = 1;
    for(int i = 1; i <= 1000; i++) {
        choose[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            choose[i][j] = (choose[i-1][j] + choose[i-1][j-1]) % MOD;
        }
    }

    string s;
    cin >> s;

    int n = s.size();

    s = "."+s;

    int k;
    cin >> k;

    // Handle edge case
    if(k == 0) {
        cout << 1 << endl;
        return 0;
    }

    for(int i = 1; i <= n; i++) {
        // We already used one operation from converting into bits
        int ops = 1;
        int cpy = i;

        while(cpy != 1) {
            cpy = __builtin_popcount(cpy);
            ops++;
        }

        // cerr << i << " bits will take " << ops << endl;
        nums[ops].emplace(i);
    }

    int ans = 0;

    int ones = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == '0') continue;

        for(int x: nums[k]) {
            if(ones > x) continue;
            cerr << "adding choose " << n-i << " " << x-ones << endl;
            ans += choose[n-i][x-ones];
            ans %= MOD;
        }

        ones++;
    }


    if(nums[k].count(ones)) {
        ans++;
    }

    // If k == 1 we counted the case where number is 1
    if(k == 1) {
        ans--;
    }

    cout << ans << endl;
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
