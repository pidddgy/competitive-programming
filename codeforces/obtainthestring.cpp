// https://codeforces.com/contest/1295/problem/C

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int T;
    cin >> T;

    while(T--) {
        string s, t;
        cin >> s >> t;

        if(s == t) {
            cout << 1 << endl;
            continue;
        }

        string z;

        map<char, vector<int>> shit;
        map<char, int> shitt;

        for(int i = 0; i < s.size(); i++) {
            shit[s[i]].emplace_back(i);
        }

        int bloop = 1;
        bool ohno = false;

        if(shit[t[0]].size() == 0) {
            ohno = true;
        }

        if(!ohno) {s
            int last = shit[t[0]][0]; // careful
            shitt[t[0]]++;

            for(int i = 1; i < t.size(); i++) {
                if(shit[t[i]].size() == 0) {
                    ohno = true;
                    break;
                }
                if(shitt[t[i]] >= shit[t[i]].size()) {
                    // cout << "cleared on " << i << endl;
                    // watch(shitt[t[i]])
                    // watch(shit[t[i]].size())
                    for(char x: "abcdefghijklmnopqrstuvwxyz") {
                        shitt[x] = 0;
                    }
                    bloop++;
                    last = 0;
                } else shitt[t[i]]++;


                int nextInd = shit[t[i]][shitt[t[i]]];
                // watch(nextInd)
                // watch(last)
                if(nextInd < last) {
                    bloop++;
                    // cout << "cleared second on " << i << endl;
                    for(char x: "abcdefghijklmnopqrstuvwxyz") {
                        shitt[x] = 0;
                    }
                    last = 0;

                } else {
                    // cout << "increasing size of " << t[i] << endl;
                    // shitt[t[i]]++;
                }

                last = nextInd;
            }
        }

        if(ohno) {
            cout << -1 << endl;
        } else {
            cout << bloop << endl; 
        }

    }
}