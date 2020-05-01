// https://codeforces.com/contest/1326/problem/D1

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

bool isPalindrome(string s) {
    int l = 0;
    int r = s.size()-1;

    while(r > l) {
        if(s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }

    return true;
}
int main() {
    // cout << isPalindrome("abba") << endl;

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        int ma = 0;
        string ans = "";
        for(int len = s.size(); len >= 1; len--) {
            // watch(len)
            for(int i = 0; i <= len; i++) {
                string built;
                // watch(i)
                for(int j = 0; j < i; j++) {
                    built += s[j];
                    // watch(j)
                }

                string end = s.substr(s.size()-(len-i));
                built += end;

                // watch(built)
                if(isPalindrome(built)) {
                    if(len > ma) {
                        ma = len;
                        ans = built;
                    }
                }

            }

            // cerr << endl;
        }

        cout << ans << endl;
    }
}