// link

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if(i == 0) {
            if(!isdigit(s[i+1])) {
                if(s[i] != '0' and isdigit(s[i]))
                s[i] -= 3;
            }
        } else if(i == s.size()-1) {
            if(!isdigit(s[i-1])) {
                if(s[i] != '0' and isdigit(s[i]))
                s[i] -= 3;
            }
        } else {
            if(!isdigit(s[i-1]) and !isdigit(s[i+1])) {
                if(s[i] != '0' and isdigit(s[i]))
                    s[i] -= 3;
            }
        }
    }

    cout << s << endl;
}