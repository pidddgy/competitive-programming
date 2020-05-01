// https://codeforces.com/contest/883/problem/E

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// #define cerr if(false) cerr

int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    set<char> seen;
    string s;
    cin >> s;
    for(char x: s) {
        seen.emplace(x);
    }

    s = "."+s;

    int m;
    cin >> m;

    string a[m+1];

    for(int i = 1; i <= m; i++) {
        cin >> a[i];        
        a[i] = "."+a[i];
    }

    vector<string> can;

    for(int i = 1; i <= m; i++) {
        bool good = true;
        for(int j = 1; j <= n; j++) {
            if(s[j] == '*') {
                if(seen.count(a[i][j])) {
                    good = false;
                }
            } else {
                if(a[i][j] != s[j]) {
                    good = false;
                }
            }
        }
        if(good) {
            can.emplace_back(a[i]);
            cerr << "emplacing back " << a[i] << endl;
        }
    }

    string alpha = "abcdefghijklmnopqrstuvwxyz";
    set<int> S;
    for(int chr = 0; chr < 26; chr++) {
        char x = alpha[chr];
        if(seen.count(x)) continue;
        
        cerr << "on char " << x << endl;

        bool good = true;
        for(string c: can) {
            bool localgood = false;
            for(int j = 1; j <= n; j++) {
                if(c[j] == x) {
                    localgood = true;
                }
            }

            if(!localgood) good = false;
        }

        if(good) S.emplace(x);
    }

    cout << S.size() << endl;
}