// https://codeforces.com/contest/1031/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int l = 1;
    int r = 1000000;

    set<int> day1, day2;
    while(l <= r) {
        int m = (l+r)/2;

        int rem = a, sec = 0;
        set<int> d1t;
        set<int> d2t;
        for(int i = m; i >= 1; i--) {
            if(rem >= i) {
                rem -= i;
                d1t.emplace(i);
            } else {
                sec += i;
                d2t.emplace(i);
            }
        }

        if(sec > b) {
            r = m-1;
        } else {
            l = m+1;
            day1 = d1t, day2 = d2t;
        }
    }

    for(set<int> x: vector<set<int>>({day1, day2})) {
        cout << x.size() << endl;
        for(int y: x) {
            cout << y << " ";
        }
        cout << endl;
    }
}