// https://codeforces.com/contest/1265/problem/D

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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<int, int> cpy;

    int sum = 0;
    for(int i = 0; i <= 3; i++) {
        cin >> cpy[i];
        sum += cpy[i];
    }

    for(int st = 0; st <= 3; st++) {
        if(!cpy[st]) continue;

        map<int, int> mp = cpy;
        mp[st]--;
        vector<int> out = {st};
        int cur = st;

        for(int i = 1; i <= sum-1; i++) {
            if(mp[cur-1]) {
                out.push_back(cur-1);
                mp[cur-1]--;
                cur--;
            } else if(mp[cur+1]) {
                out.push_back(cur+1);
                mp[cur+1]--;
                cur++;
            } else break;
        }

        if(sz(out) == sum) {
            cout << "YES" << endl;
            for(int x: out) {
                cout << x<< " ";
            }
            cout << endl;
            exit(0);
        }
    }

    cout << "NO" << endl;
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
