// https://codeforces.com/contest/883/problem/H 

#include <bits/stdc++.h>
using namespace std;
// #define cerr if(false) cerr
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

map<char, int> cnt;
vector<deque<char>> ans;

// remember that for each char in even we have 2
queue<char> odd, even;

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    s = "."+s;

    for(int i = 1; i <= n; i++) {
        cnt[s[i]]++;
    }

    for(auto &x: cnt) {
        if(x.se&1) {
            odd.push(x.fi);
            x.se--;            
        }

        while(x.se) {
            even.push(x.fi);
            x.se -= 2;
        }
    }

    for(;;) {
        if((sz(odd) == 0) or (sz(even) % sz(odd) == 0)) {
            int each;
            if(sz(odd) == 0) each = sz(even);
            else each = sz(even) / sz(odd);

            cout << max(1, sz(odd)) << endl;
            int tmp = sz(odd);
            for(int i = 1; i <= max(1, tmp); i++) {
                deque<char> ans;
                if(sz(odd)) ans.push_back(odd.front());
                odd.pop();

                for(int j = 1; j <= each; j++) {
                    ans.push_front(even.front());
                    ans.push_back(even.front());
                    even.pop();
                }

                for(char x: ans) {
                    cout << x;
                }
                cout << " ";
            }
            cout << endl;

            break;
        }

        odd.push(even.front());
        odd.push(even.front());
        even.pop();
    }



}

/*

the strings either have to be all even or all odd

if there is any letter with odd frequency then they must all be odd
    try to divide the rest equally amonst the odd frequency letters
    if you can't divide them then put them all into strings of size 1

otherwise put them all into one string

*/

// Did you read the bounds?
// Did you make typos?
// Are there edge cases (N=1?)
// Are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// Integer overflow?
// DS reset properly between test cases?
// Is using long longs causing TLE?
// Are you using floating points?
