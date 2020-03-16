// https://codeforces.com/contest/1303/problem/C

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;

const string alpha = "abcdefghijklmnopqrstuvwxyz";
int T;

int main() {
    cin >> T;

    while(T--) {
        string s;
        cin >> s;

        deque<char> keyboard;
        unordered_map<char, bool> used;
        map<char, set<char>> G;

        watch(s)
        watch(s.size())
        if(s.size() == 2) {
            G[s[0]].emplace(s[1]);
            G[s[1]].emplace(s[0]);
        } else if(s.size() == 1){
            cout << "YES" << endl;
            cout << alpha << endl;
            continue;
        } else {
            for(int i = 1; i < s.size()-1; i++) {
                G[s[i]].emplace(s[i-1]);
                G[s[i]].emplace(s[i+1]);
                G[s[i+1]].emplace(s[i]);
                G[s[i-1]].emplace(s[i]);
            }   
        }

        bool no = false;
        for(int i = 0; i < 26; i++) {
            char x = alpha[i];

            if(G[x].size() > 2) {
                cout << "NO" << endl;
                no = true;
                break;
            }
        }

        if(no) continue;

        char st = '?';
        for(int i = 0; i < 25; i++) {
            char x = alpha[i];
            // watch(x)
            // watch(G[x].size())
            if(G[x].size() == 1) {
                st = x;
            }
        }

        if(st == '?') {
            cout << "NO" << endl;
            cerr << "bloop" << endl;
            continue;
        }

        // watch(st)
        deque<char> ans;

        queue<char> Q = queue<char>();
        unordered_map<char, bool> vis = unordered_map<char, bool>();

        Q.push(st);
        vis[st] = true;

        while(!Q.empty()) {
            char S = Q.front(); 
            Q.pop();

            ans.push_back(S);
            for(char x: G[S]) {
                if(!vis[x]) {
                    Q.push(x);
                    vis[x] = true;
                }
            }
        }
        for(int i = 0; i < 26; i++) {
            char x = alpha[i];

            if(!vis[x]) {
                ans.push_back(x);
            }
        }

        cout << "YES" << endl;
        for(char x: ans) {
            cout << x;
        }
        cout << endl;
    }
}