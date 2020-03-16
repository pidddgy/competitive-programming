// https://codeforces.com/contest/1203/problem/D1

#include <bits/stdc++.h>
using namespace std;

bool subseq(string a, string b) {
    if(a.size() < b.size()) return false;

    int shit = a.size()-1;
    for(int i = b.size()-1; i >= 0; i--) {
        while(a[shit] != b[i] and shit >= 0) {
            shit--;
        }
        if(a[shit] == b[i]) {
            shit--;
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    // cout << subseq("ssfdhdsffisdfsdft", "ssfd") << endl;
    string s, t;
    cin >> s >> t;

    int ma = 0;

    for(int i = 0; i < s.size(); i++) {
        for(int j = i; j < s.size(); j++) {
            string thing;
            for(int k = 0; k < s.size(); k++) {
                if(k < i or k > j) {
                    thing += s[k];
                }
            }

            if(subseq(thing, t)) {
                ma = max(ma, j-i+1);
            }

        }
    }

    cout << ma << endl;
}