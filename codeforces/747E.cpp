// https://codeforces.com/contest/747/problem/E

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define psi pair<string, int>
#define fi first
#define se second

vector<string> split(string s, char delim) {
    vector<string> res;
    string cur;
    for(char x: s) {
        if(x != delim) {
            cur += x;
        } else {
            res.emplace_back(cur);
            cur = "";
        }
    }
    res.emplace_back(cur);

    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<string> spl = split(s, ',');
    vector<psi> parsed;
    for(int i = 0; i < spl.size(); i += 2) {
        parsed.emplace_back(psi(spl[i], stoi(spl[i+1])));
    }

    stack<int> S;
    map<int, vector<string>> ans;
    for(int i = 0; i < parsed.size(); i++) {
        psi x = parsed[i];

        if(!S.empty()) S.top()--;
        S.push(x.se);

        // cerr << "pushing " << x.fi << " to " << S.size() << endl;    
        ans[S.size()].emplace_back(x.fi);

        while(S.size() and S.top() == 0) {
            S.pop();
        }
    }

    cout << ans.size() << endl;
    for(auto x: ans) {
        for(string y: x.se) {
            cout << y << " ";
        }
        cout << endl;
    }
}