// https://codeforces.com/contest/1157/problem/C2

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

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> dq;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        dq.emplace_back(x);
    }

    string ans;
    int last = 0;

    while(dq.size()) {
        if(dq.front() < dq.back()) {
            if(dq.front() <= last) {
                break;
            }

            ans += 'L';
            last = dq.front();
            dq.pop_front();
        } else if(dq.back() < dq.front()) {
            if(dq.back() <= last) {
                break;
            }

            ans += 'R';
            last = dq.back();
            dq.pop_back();
        } else if(dq.front() == dq.back()) {
            break;
        }
    }

    watch(ans)
    watch(last)
    
    int lcpy = last;
    deque<int> dqcpy = dq;
    string l;

    while(dqcpy.size()) {
        if(dqcpy.front() > lcpy) {
            lcpy = dqcpy.front();
            dqcpy.pop_front();
            l += 'L';
        } else break;
    }

    int rcpy = last;
    dqcpy = dq;
    string r;

    while(dqcpy.size()) {
        watch(dqcpy.back())
        if(dqcpy.back() > rcpy) {
            cerr << "appending" << endl;
            rcpy = dqcpy.back();
            dqcpy.pop_back();
            r += 'R';
        } else break;
    }

    if(l.size() > r.size()) {
        ans += l;
    } else {
        ans += r;
    }

    cout << ans.size() << endl;
    cout << ans << endl;
}

/*

use deque

take from left, right, minimizing where possible
    -> if at any point the minimum is <= last element taken, break

if we hit a point where they are same try going from left->right and right->left
    -> works because if you take either left or right you can never take the other one


*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
