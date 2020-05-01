// https://codeforces.com/contest/832/problem/B

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
string good;
string pattern;
string noast;
set<char> goodS;


bool match(string s, string pat) {
    if(pat.size() != s.size()) {
        return false;
    }

    for(int i = 0; i < pat.size(); i++) {
        if(pat[i] == '?') {
            if(!goodS.count(s[i])) {
                return false;
            }
        } else if(pat[i] == '*') {
            if(goodS.count(s[i])) {
                return false;
            }
        } else if(pat[i] != s[i]) {
            return false;
        }
    }

    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> good >> pattern;
    for(int i = 0; i < good.size(); i++) {
        goodS.emplace(good[i]);
    }

    int asind = -1;
    for(int i = 0; i < pattern.size(); i++) {
        if(pattern[i] != '*') {
            noast.push_back(pattern[i]);
        } else {
            asind = i;
        }
    }
    int n;
    cin >> n;

    while(n--) {
        string q;
        cin >> q;
        
        vector<string> tr;

        if(pattern.size() == q.size()+1) {
            tr.push_back(noast);
        }

        tr.push_back(pattern);

        if(pattern.size() < q.size() and asind != -1) {
            string comp;
            for(int i = 0; i < pattern.size(); i++) {
                comp.push_back(pattern[i]);
                if(pattern[i] == '*') {
                    for(int j = 0; j < q.size()-pattern.size(); j++) {
                        comp.push_back('*');
                    }
                }
            }
            tr.push_back(comp);
        }

        string ans = "NO";
        for(string x: tr) {
            // cerr << "trying " << x << endl;
            if(match(q, x)) ans = "YES";
        }

        cout << ans << endl;
    }    
}