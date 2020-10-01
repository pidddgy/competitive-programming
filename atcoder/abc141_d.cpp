// https://atcoder.jp/contests/abc141/tasks/abc141_d

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

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    priority_queue<int> pq;

    for(int i = 1; i <= N; i++) {
        int x;
        cin >> x;

        pq.push(x);
    }

    for(int i = 1; i <= M; i++) {
        int val = pq.top(); pq.pop();

        pq.emplace(val/2);
    }

    int sum = 0;
    while(pq.size()) {
        sum += pq.top();
        pq.pop();
    }

    cout << sum << endl;
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
