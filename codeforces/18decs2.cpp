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

int n;
deque<pair<pii, int>> dq;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    cin >> n;

    for(int i = 1; i <= n; i++) {
        int a, t;
        cin >> a >> t;

        // time entered, seniority, time taking
        dq.push_back({pii(a, i), t});
    }

    sort(all(dq));
    reverse(all(dq));

    for(auto x: dq) {
        cerr << x.fi.fi << " " << x.fi.se << " " << x.se << endl;
    }
    cerr << endl;

    // pq stores seniority, time entered, time taking
    priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<pair<pii, int>>> pq;

    int time = -1;
    int ans = 0;
    while(sz(dq) or sz(pq)) {
        pair<pii, int> nxt;
        // take next cow
        if(sz(pq)) {
            nxt = pq.top(); pq.pop();
            ans = max(ans, time-nxt.fi.se);
            time += nxt.se;
        } else if(sz(dq)) {
            // this cow starts right away
            nxt = dq.back(); dq.pop_back();
            time = nxt.fi.fi + nxt.se;
        }

        while(sz(dq) and dq.back().fi.fi <= time) {
            auto p = dq.back();
            dq.pop_back();
            pq.push({{p.fi.se, p.fi.fi}, p.se});
        }
    }

    cout << ans << endl;
}

/*

pair<pii, int>
keep track of current time
while true
    if we are not blocked then take the next cow. max answer with current time - starting time

    add to time

    we are blocked up to x time. so collect all cows up to x time
    push into priority queue of seniority
    
*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
