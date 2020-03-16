// https://codeforces.com/contest/1307/problem/C

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define fi first
#define se second
using namespace std;

const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main() {
    #define int long long
    unordered_map<char, int> cnt;
    unordered_map<string, int> scnt;

    string s;
    cin >> s;

    for(int i = s.size()-1; i >= 0; i--) {
        scnt[string(1, s[i])]++;
        cerr << "cnt of " << string(1, s[i]) << " incremented" << endl;
        for(int j = 0; j < 26; j++) {
            cerr << "HI" << endl;
            string b;
            b.push_back(s[i]);

            b.push_back(alpha[j]);

            cerr << "increasing scnt of " << b << " by " << cnt[alpha[j]] << endl;
            scnt[b] += cnt[alpha[j]];
        }
        cnt[s[i]]++;

        cerr << endl;
    }

    int ma = 0;
    for(pair<string, int> x: scnt) {
        if(x.second > ma) {
            cerr << "using " << x.fi << endl;
            ma = max(ma, x.second);
        }
    }

    cout << ma << endl;
}