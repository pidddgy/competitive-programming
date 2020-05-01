// https://codeforces.com/contest/600/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr

bool valNum(string x) {
    if(x == "") return false;
    if(x[0] == '0' and x.size() > 1) return false;
    for(char y: x) {
        if(!isdigit(y)) {
            return false;
        }
    }

    return true;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    vector<string> a;
    vector<string> b;

    string cur = "";

    for(int i = 0; i < s.size(); i++) {
        if((s[i] == ',' or s[i] == ';')) {
            cerr << "hit on " << i << endl;
            cerr << "cur is " << cur << endl;
            if(valNum(cur)) {
                a.push_back(cur);
            } else {
                b.push_back(cur);
            }
            cur = "";
            continue;
        }

        cur += s[i];
    }
    if(valNum(cur)) {
        a.push_back(cur);
    } else {
        b.push_back(cur);
    }

    if(a.size() == 0) cout << "-" << endl;
    else {
        cout << "\"";
        for(int i = 0; i < a.size(); i++) {
            cout << a[i];
            if(i != a.size()-1) {
                cout << ",";
            }
        }
        cout << "\"" << endl;
    }

    if(b.size() == 0) cout << "-" << endl;
    else {
        cout << "\"";
        for(int i = 0; i < b.size(); i++) {
            cout << b[i];
            if(i != b.size()-1) {
                cout << ",";
            }
        }
        cout << "\"" << endl;
    }
}