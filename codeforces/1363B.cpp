// https://codeforces.com/contest/1363/problem/B

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << (#x) << " is " << (x) << endl;
#define endl '\n' 

string s;
int cnt(char chr, int l, int r) {
    int res = 0;
    for(int i = l; i <= r; i++) {
        if(s[i] == chr) res++;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        cin >> s;

        int n = s.size();
        vector<string> valid;

        for(int i = 0; i <= n; i++) {
            string x;
            string y;

            for(int j = 1; j <= i; j++) {
                x += '1';
                y += '0';
            }

            for(int j = i+1; j <= n; j++) {
                x += '0';
                y += '1';
            }

            valid.emplace_back(x);
            valid.emplace_back(y);
        }

        int ans = INT_MAX;
        for(string x: valid) {
            int edit = 0;
            for(int i = 0; i < x.size(); i++) {
                if(x[i] != s[i]) {
                    edit++;
                }
            }

            ans = min(ans, edit);
        }

        cout << ans << endl;
    }
}
