// https://codeforces.com/contest/1251/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int n = s.size();
        int a[n];
        for(int i = 0; i < n; i++) {
            a[i] = s[i]-'0';
        }

        deque<int> even;
        deque<int> odd;
        
        for(int i = 0; i < n; i++) {
            if(a[i]%2) {
                odd.emplace_back(a[i]);
            } else {
                even.emplace_back(a[i]);
            }
        }

        while(even.size() and odd.size()) {
            if(even.front() < odd.front()) {
                cout << even.front();
                even.pop_front();
            } else {
                cout << odd.front();
                odd.pop_front();
            }
        }
        for(int x: even) cout << x;
        for(int x: odd) cout << x;

        cout << endl;
    }
}