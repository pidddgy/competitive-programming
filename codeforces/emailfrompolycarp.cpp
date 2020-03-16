// http://codeforces.com/contest/1185/problem/B

#include <bits/stdc++.h>
#define pci pair<char, int>
#define fi first
#define se second
using namespace std;
int main() {
    int n;
    cin >> n;

    while(n--) {
        string s,t;
        cin >> s >> t;

        vector<pci> ss;
        vector<pci> tt;

        char prev = s[0];
        int cnt = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] != prev) {
                ss.emplace_back(prev, cnt);
                prev = s[i];
                cnt = 1;
            } else cnt++;
        }

        ss.emplace_back(prev, cnt);

        prev = t[0];
        cnt = 1;
        for(int i = 1; i < t.size(); i++) {
            if(t[i] != prev) {
                tt.emplace_back(prev, cnt);
                prev = t[i];
                cnt = 1;
            } else cnt++;
        }

        tt.emplace_back(prev, cnt);

        if(ss.size() != tt.size())
            cout << "NO" << endl;
        else {
            bool bad = false;
            for(int i = 0; i < ss.size(); i++) {
                if(ss[i].fi != tt[i].fi) bad = true;
                if(ss[i].se > tt[i].se) bad = true;

                if(bad) break;
            }

            if(bad) cout << "NO" << endl;
            else cout << "YES" << endl;
        }




        // for(auto x: ss) {
        //     cout << x.fi << " " << x.se << endl;
        // }
        // cout << endl;

        // for(auto x: tt) {
        //     cout << x.fi << " " << x.se << endl;
        // }

    }
}