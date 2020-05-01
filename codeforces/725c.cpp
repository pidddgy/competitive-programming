// https://codeforces.com/contest/725/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    for(int i = 0; i < s.size()-1; i++) {
        if(s[i] == s[i+1]) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    map<char, bool> seen;
    for(int i = 0; i < s.size(); i++) {
        if(seen[s[i]]) {
            cerr << "seen " << s[i] << endl;
            rotate(s.begin(), s.begin()+i, s.end());
            break;
        }
        seen[s[i]] = true;
    }

    cerr << s << endl;
    int ind = 1;
    while(s[ind] != s[0]) {
        ind++;
        cerr << "accessing" << ind << endl;
    }

    s.erase(s.begin()+ind);
    int sh = (ind+1)/2;
    string a = s.substr(sh+13) + s.substr(0, sh);
    string b = s.substr(sh, 13);
    reverse(b.begin(), b.end());
    cout << a << endl;
    cout << b << endl;


}