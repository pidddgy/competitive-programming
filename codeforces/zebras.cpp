// https://codeforces.com/contest/949/problem/A

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define fi first
#define se second
bool used[300000];

vector<int> ans[300000];
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int N = s.size();
    s = "."+s;

    // .fi = 0 if zebra, 1 if not zebra
    set<int> zebra;
    set<int> nonzebra;
  
    int pos = 1;
    for(int i = 1; i <= N; i++) {
        if(s[i] == '0') {
            if(nonzebra.empty()) {
                ans[pos].emplace_back(i);
                zebra.emplace(pos);
                pos++;
            } else if(nonzebra.size()) {
                int ind = *nonzebra.begin();
                ans[ind].emplace_back(i);

                zebra.emplace(ind);
                nonzebra.erase(nonzebra.begin());
            } else {
                ans[pos].emplace_back(i);
                zebra.emplace(pos);
                pos++;
            }
        } else if (s[i] == '1') {
            if(zebra.empty()) {
                cout << -1 << endl;
                return 0;
            } else if(zebra.size()) {
                int ind = *zebra.begin();
                zebra.erase(zebra.begin());

                ans[ind].emplace_back(i);
                nonzebra.emplace(ind);
            } else {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    if(nonzebra.size()) {
        cout << -1 << endl;
        return 0;
    }
    cout << pos-1 << endl;
    for(int i = 1; i <= pos-1; i++) {
        cout << ans[i].size() << " ";
        for(int y: ans[i]) {
            cout << y << " ";
        }
        cout << endl;
    }

  
}

