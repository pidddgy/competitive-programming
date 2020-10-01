// https://codeforces.com/contest/1295/problem/C

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        map<char, vector<int>> inds;
        
        string s, t;
        cin >> s >> t;

        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            char x = s[i];
            inds[x].emplace_back(i);
        }

        for(char x: string("abcdefghijklmnopqrstuvwxyz")) {
            sort(inds[x].begin(), inds[x].end());
        }

        bool br = false;
        for(int i = 0; i < t.size(); i++) {
            if(inds[t[i]].empty()) {
                cout << -1 << endl;
                br = true;
                break;
            }
        }

        if(br) continue;
        
        int pos = 0;
        int curInd = -1;
        while(pos < t.size()) {
            char need = t[pos];
            if(curInd > inds[need][inds[need].size()-1]) {
                curInd = -1;
                ans++;
            }
            assert(inds[need].size());
            int l = 0;
            int r = inds[need].size()-1;
            int lastgood = -1;
            while(l <= r) {
                int m = (l+r)/2;
                if(curInd <= inds[need][m]) {
                    lastgood = inds[need][m];
                    r = m-1;
                } else {
                    l = m+1;
                }
            }
            assert(lastgood != -1);
            curInd = lastgood+1;
            pos++;
        }

        // assert(curInd == 0);
        // watch(curInd)
        if(curInd != -1) ans++;
        cout << ans << endl;

        for(char x: string("abcdefghijklmnopqrstuvwxyz")) {
            inds[x].clear();
        }
    }
}
