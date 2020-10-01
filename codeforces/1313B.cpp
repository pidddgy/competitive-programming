// https://codeforces.com/contest/1313/problem/B

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
    int n, x, y;
    cin >> n >> x >> y;

    // doing worst
    // how many people can we make <= x+y?

    // pairing everyone less than x with their unique counterpart to create x+y
    int part1 = min(x-1, n-y);
    int part2 = min(y-1, n-x);

    // we also may have extra on the end
    int worst = 1 + part1 + part2 + min(x-1-part1, y-1-part2);

    // pairing 
    // we subtract one because we have to make the sum x+y+1
    part1 = max(0LL, min(x-1, n-y-1));
    part2 = max(0LL, min(y-1, n-x-1));

    
    // we also have extra on the right end if we dont have enough on the left end
    int best = n - (part1 + part2 + min(n-x-part2, n-y-part1));

    // when using the "extra" elements at the end, we might be able to use the elements on the other side but it will never create a more optimal answer (exchange)

    cout << best << " " << worst << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) solve();
}

/*
2345
1245

2345
5421

sample 2:

sum = 7
12456
12356

2, 4, 7, 10, 12

12456
65321

7, 7, 7, 7, 7

let the list of possible places from round 1 and 2 be R_1 and R_2 respectively

in best case, we want to match numbers from R_! and R_2 such that as many of them as possible <= x+y
int worst case, we want to match so that as many as possible > x+y

for best case, iterate over numbers from smallest to biggest. take the biggest element so that the sum is still <= x+y
proof: if a small number uses a bigger number and we can swap it with a more leftmost element, that might enable us to use that bigger number with another element. so it is never suboptimal to use this strategy.

for worst case, iterate over numbers from smallest to biggest. take the smallest element so that the sum is > x+y
proof: if in an optimal solution a small number uses a bigger number, we can swap it with a smaller element (similar to above). if an optimal solution pairs an element a with an element that has sum <= x+y when it is possibl to make it > x+y, we can swap it with that bigger number. Worst case, we miss out on one possible match so our greedy strategy is never suboptimal.

implementation: we can use upper_bound. for best case decrement by 1, and in worst case do not decrement

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
