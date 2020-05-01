// https://codeforces.com/contest/518/problem/B

#include <bits/stdc++.h>
using namespace std;

const string lalpha = "abcdefghijklmnopqrstuvwxyz";
const string ualpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main() {
    string s, t;
    cin >> s >> t;

    unordered_map<char, char> inv;
    for(int i = 0; i < 26; i++) {
        inv[lalpha[i]] = ualpha[i];
        inv[ualpha[i]] = lalpha[i];
    }

    unordered_map<char, int> cnt;
    for(char x: t) {
        cnt[x]++;
    }

    int y = 0;
    int w = 0;

    unordered_map<int, bool> resolved;
    for(int i = 0; i < s.size(); i++) {
        if(cnt[s[i]]) {
            cnt[s[i]]--;
            y++;

            resolved[i] = true;
        }
    }

    for(int i = 0; i < s.size(); i++) {
        if(!resolved[i]) {
            if(cnt[inv[s[i]]]) {
                cnt[inv[s[i]]]--;
                w++;

                resolved[i] = true;
            }
        }
    }

    cout << y << " " << w << endl;
}