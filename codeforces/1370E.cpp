// https://codeforces.com/contest/1370/problem/E

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
#define int long long

const int maxn = 1000500;

int n;
string s, t;

deque<int> pos[5];

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    cin >> s >> t;

    int s1 = 0, t1 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') s1++;
        if(t[i] == '1') t1++;

        if(s[i] == '1' and t[i] == '0') {
            pos[1].emplace_back(i);
        } else if(s[i] == '0' and t[i] == '1') {
            pos[0].emplace_back(i);
        }
    }

    if(s1 != t1) {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 0; i <= 1; i++) {
        sort(pos[i].begin(), pos[i].end());
    }

    int ans = 0;

    while(pos[0].size()+pos[1].size()) {
        int cur = '?';

        if(pos[0].empty()) {
            cur = 1;
        } else if(pos[1].empty()) {
            cur = 0;
        } else if(pos[0].front() < pos[1].front()) {
            cur = 0;
        } else {
            cur = 1;
        }

        int last = -1;
        
        while(pos[cur].size() and pos[cur^1].size() and pos[cur].front() > last and pos[cur^1].front() > pos[cur].front()) {
            last = pos[cur].front();
            pos[cur].pop_front();
            cur ^= 1;
            last = pos[cur].front();
            pos[cur].pop_front();
            cur ^= 1;
        }

        ans++;
    }

    assert(pos[0].empty());
    assert(pos[1].empty());

    cout << ans << endl;
}