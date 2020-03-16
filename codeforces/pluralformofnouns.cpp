// https://codeforces.com/problemsets/acmsguru/problem/99999/460

#include <bits/stdc++.h>
using namespace std;
int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        string s;
        cin >> s;

        int N = s.size();
        if(N >= 2 && (s[N-2] == 'c') && s[N-1] == 'h') {
            s += "es";
        } else if(s[N-1] == 'x' || s[N-1] == 's' || s[N-1] == 'o') {
            s += "es";
        }
        
        
        else if(N >= 2 && s[N-2] == 'f' && s[N-1] == 'e') {
            s.pop_back();
            s.pop_back();
            s += "ves";
        } else if(s[N-1] == 'f') {
            s.pop_back();
            s += "ves";
        }


        else if(s[N-1] == 'y') {
            s.pop_back();
            s += "ies";
        }

        else {
            s += "s";
        }

        cout << s << endl;
    }
}