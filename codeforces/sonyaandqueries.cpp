// https://codeforces.com/contest/713/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    #define cerr if(false) cerr
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);
    #define endl '\n'

    int t;
    cin >> t;

    unordered_map<string, int> cnt;

    for(int q = 1; q <= t; q++) {
        char type;
        cin >> type;

        if(type == '+') {
            string s;
            cin >> s;

            string b;
            for(char x: s) {
                if((x-'0') % 2 == 0) {
                    b += "0";
                } else {
                    b += "1";
                }
            }

            while(b.size() != 18) b = "0"+b;
            cerr << "adding " << b << endl;

            cnt[b]++;
        } else if(type == '-') {
            string s;
            cin >> s;

            string b;
            for(char x: s) {
                if((x-'0') % 2 == 0) {
                    b += "0";
                } else {
                    b += "1";
                }
            }

            while(b.size() != 18) b = "0"+b;
            
            assert(cnt[b] > 0);
            cnt[b]--;
        } else if(type == '?') {
            string b;
            cin >> b;
    
            while(b.size() != 18) b = "0"+b;

            cout << cnt[b] << endl;
        }
    }
}