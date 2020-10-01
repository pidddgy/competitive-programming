// https://codeforces.com/contest/1277/problem/D

#include <bits/stdc++.h>
using namespace std;
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

void solve() {
    int n;
    cin >> n;

    set<string> s01, s10;
    vector<string> s(n);
    vector<bool> have(2);

    for(int i = 0; i < n; i++) {
        cin >> s[i];

        if(s[i][0] == '0' and s[i].back() == '1') {
            cerr << "emplacing " << s[i] << " into s01" << endl;
            s01.emplace(s[i]);
        }

        if(s[i][0] == '1' and s[i].back() == '0') {
            s10.emplace(s[i]);
        }

        have[s[i][0]-'0'] = have[s[i].back()-'0'] = true;
    }

    if(have[0] and have[1] and s01.empty() and s10.empty()) {
        cout << -1 << endl;
        return;
    }

    vector<int> rev;
    for(int i = 0; i < n; i++) {
        string r = s[i];
        reverse(r.begin(), r.end());
        watch(s[i])
        watch(r)
        // replace all 01 with 10, otherwise replace all 10 with 01
        if(s01.size() > s10.size()+1) {
            if(s[i][0] == '0' and s[i].back() == '1')
            if(!s10.count(r)) {
                rev.emplace_back(i);
                cerr << "not found in s10, emplacing " << r << endl;
            }
        } else if(s10.size() > s01.size()+1) {
            if(s[i][0] == '1' and s[i].back() == '0')
            if(!s01.count(r)) {
                cerr << "emplacing " << r << endl;
                rev.emplace_back(i);
            }
        }
        cerr << endl;
    }

    int ans = abs((int)s01.size()-(int)s10.size())/2;

    cout << ans << endl;
    for(int i = 0; i < ans; i++) {
        cout << rev[i]+1 << " ";
    }
    cout << endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}