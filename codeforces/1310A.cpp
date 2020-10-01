// https://codeforces.com/contest/1310/problem/A

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
// #define cerr cout
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

map<int, vector<int>> m;
set<int> S;
vector<int> nums;

int a[maxn], b[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) {
        // nums.emplace_back(a[i]);
        S.emplace(a[i]);
        m[a[i]].emplace_back(b[i]);
    }

    // nums.emplace_back(2e9);
    S.emplace(2e9);

    for(int x: S) nums.emplace_back(x);



    int ans = 0;
    priority_queue<pii> pq;
    for(int i = 0; i < sz(nums)-1; i++) {
        cerr << "on " << nums[i] << endl;
        for(int x: m[nums[i]]) {

            cerr << "pushing " << x << " " << nums[i] << endl;
            pq.emplace(x, nums[i]);
        }

        int cur = nums[i];

        while(cur < nums[i+1] and sz(pq)) {
            pii p = pq.top();
            pq.pop();

            int pushed = cur-p.se;

            cerr << "placing " << p.fi << " " << p.se << " on " << cur << endl;
            cerr << "has cost " << pushed*p.fi << endl;
            ans += pushed*p.fi;

            cur++;
        }
        cerr << endl;
    }

    cout << ans << endl;
}

/*

we want to iterate over, greedily incrementing the highest cost types as little as possible

for i in all the numbers (events, put one event very far to the right)
    push all the new elements into the priority queue

    set current element to i

    until either current element = nums[i+1] or pq empty
        push up




     





*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
