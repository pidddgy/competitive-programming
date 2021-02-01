// https://codeforces.com/problemset/problem/216/E

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

int k, b, n;
int mod;
int root(int x) {
    if(x == 0) return 0;
    if((x % mod) == 0) return mod;
    return n%mod;
}

// find y where x-y mod k-1 = b
int f(int x) {
    return (x+(mod) - b) % mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> b >> n;
    mod = k-1;

    map<int, int> cnt;
    cnt[0] = 1;
    int ans = 0;
    int z = 0;
    int sum = 0;
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        
        sum += x;

         // contiguous segments of 0s are bad
        if(x == 0) cur++;
        else {
            // cerr << "run of size " << cur << endl;
            z += (cur*(cur+1))/2;
            cur = 0;
        }

        ans += cnt[f(sum)];

        cnt[sum%mod]++;
        cerr << endl;
    }
    z += (cur*(cur+1))/2;

    if(b == 0) ans = z;
    else if(b == k-1) ans -= z;

    cout << ans << endl;
}

/*

think of digits as coeffients on powers of b
digital sum is sum of coefficients 

the bound on number of iterations to find digital sum is probably small

digital root is:
    if n == 0 return 0
    if n % b-1 == 0
        return b-1
    else n mod b-1

digital sum congruent to n mod (b-1)

digital root is sum(sum(sum))... and so on so n mod(b-1)

count subarrays that has sum % k-1 = b

edge cases are if b-1 = 0 and b = k-1

if k-1 = 0 we only consider the runs of 0 because any other subarray with nonzero element will have nonzero digital root
if b == k-1 we want to subtract the runs of 0 because they don't count


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
