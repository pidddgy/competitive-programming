// https://dmoj.ca/problem/coci06c2p3

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pcc pair<char, char>
#define fi first
#define se second
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n1, n2;
    cin >> n1 >> n2;

    string s, t;
    cin >> s >> t;

    vector<pcc> line;

    for(int i = s.size()-1; i >= 0; i--) {
        line.emplace_back(pcc(s[i], 'R'));
    }

    for(int i = 0; i < n2; i++) {
        line.emplace_back(pcc(t[i], 'L'));
    }

    int T;
    cin >> T;

    while(T--) {
        for(int i = 1; i < line.size(); i++) {
            if(line[i].se == 'L' and line[i-1].se == 'R') {
                swap(line[i], line[i-1]);
                i++;
            }
        }
    }

    for(pcc x: line) {
        cout << x.fi;
    }
    cout << endl;
}