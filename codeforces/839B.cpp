// https://codeforces.com/contest/839/problem/B

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n'
#define ld long double
// #define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define all(x) (x).begin(), (x).end()

void solve() {
    
}

const int maxn = (int)1e4+50;
const int maxk = (int)105;

int n, k;
int cpy[maxk];
int a[maxk];

void reset() {
    for(int i = 1; i <= k; i++) {
        a[i] = cpy[i];
    }
}

void pr() {
    for(int i = 1; i <= k; i++) {
        cerr << a[i] << " ";
    }
    cerr << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= k; i++) {
        cin >> a[i];
    }

    string ans = "NO";
    for(int i = 0; i <= n; i++) {
        cerr << "trying " << i << endl;
        priority_queue<int> pq;

        for(int i = 1; i <= k; i++) {
            cerr << "pushing " << a[i] << endl;
            pq.push(a[i]);
        }

        int have = i;
        watch(have)
        cerr << "4" << endl;
        for(;;) {
            if(pq.empty()) break;
            if(!have) break;

            int top = pq.top(); pq.pop();
            int take = min(top/4, have);

            watch(take)
            
            if(take == 0) {
                pq.push(top);
                break;
            }
            top -= min(top, 4*take);
            have -= take;

            if(top > 0)
                pq.push(top);
        }

        cerr << "4 rounded up" << endl;
        for(;;) {
            if(pq.empty()) break;
            if(!have) break;

            int top = pq.top(); pq.pop();
            int take = min((top+3)/4, have);
            watch(take)
            
            if(take == 0) {
                pq.push(top);
                break;
            }
            top -= min(top, 4*take);
            have -= take;

            if(top > 0)
                pq.push(top);
        }

        have = 2*n + n-i;
        cerr << "doing rest" << endl;
        watch(have)

        watch(sz(pq))

        for(;;) {
            if(pq.empty()) break;
            if(!have) break;

            int top = pq.top(); pq.pop();
            int take = min((top+1)/2, have);

            watch(top);
            watch(take)

            if(take == 0) break;
            top -= min(top, 2*take);
            have -= take;

            if(top > 0)
                pq.push(top);
        }

        int sum = 0;
        while(sz(pq)) {
            sum += pq.top();
            pq.pop();
        }

        if(sum <= n-i) {
            cerr << "a" << endl;
            ans = "YES";
        }
        cerr << endl;
    }

    cout << ans << endl;
}

/*

side sections have only 1 group
1
2

middle section can take at most 2 groups
1, 1
1, 2
2, 1

or can take 4

4, 0

in the first case, middle sections are just like side sections but with 1 "free"

brute force on number of 4 middle vs 2+1 middle

always use 4 middles on the big groups?

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
