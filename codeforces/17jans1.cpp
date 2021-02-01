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

const int maxn = 10500;
int n, t;

int d[maxn];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    cin >> n >> t;

    for(int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    int ans = 0;
    int l = 1, r = n;
    while(l <= r) {
        int m = (l+r)/2;

        cerr << "trying " << m << endl;
        // ending time
        // deque<int> dq;
        priority_queue<int, vector<int>, greater<int>> pq;

        int ind = 1;
        for(int i = 1; i <= t; i++) {
            cerr << "on " << i << endl;
            while(sz(pq) and i >= pq.top()) {
                cerr << "pop at " << pq.top() << endl;
                pq.pop();
            }

            while(sz(pq) < m) {
                if(ind <= n) {
                    pq.push(i+d[ind]);
                    ind++;
                } else break;
            }

            if(ind == n+1) {
                break;
            }
        }

        while(sz(pq) and t+1 >= pq.top()) {
            cerr << "pop at " << pq.top() << endl;
            pq.pop();
        }

        if(ind == n+1 and pq.empty()) {
            cerr << "ok" << endl;
            ans = m;
            r = m-1;
        } else {
            l = m+1;
        }
        cerr << endl;
    }

    cout << ans << endl;
}

/*

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper?
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
