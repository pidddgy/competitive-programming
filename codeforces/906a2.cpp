// https://codeforces.com/contest/906/problem/A

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define pci pair<char, int>
#define fi first
#define se second
#define cerr if(false) cerr

int n;
set<char> suspect;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    int shocks = 0;
    int mi = -1;
    bool first = true;

    // for(int i = 0 ; i < 26; i++) {
    //     suspect.emplace('a'+i);
    // }
    for(char x: string("abcdefghijklmnopqrstuvwxyz")) {
        suspect.emplace(x);
    }
    cout << suspect.size() << endl;
    // for(int q = 1; q <= n; q++) {
    //     char type;
    //     cin >> type;

    //     string s;
    //     cin >> s;

    //     if(type == '!') {
    //         shocks++;

    //         // if(first) {
    //         //     first = false;
    //         //     for(char x: s) {
    //         //         suspect.emplace(x);
    //         //     }
    //         //     continue;
    //         // }

    //         map<char, int> cnt;
    //         for(char x: suspect) {
    //             cnt[x]++;
    //         }

    //         set<int> sS;
    //         for(char x: s) sS.emplace(x);
    //         for(char x: sS) {
    //             cnt[x]++;
    //         }

    //         set<char> ne;
    //         for(pci x: cnt) {
    //             if(x.se == 2) {
    //                 ne.emplace(x.fi);
    //             }
    //         }

    //         suspect = {};
    //         for(int x: ne) {
    //             suspect.emplace(x);
    //         } 

    //         if(suspect.size() == 1 and mi == -1) {
    //             mi = shocks;
    //         }
    //     } else if(type == '.') {
    //         set<char> er;
    //         for(char x: s) {
    //             if(suspect.count(x)) er.emplace(x);
    //         }
    //         for(char x: er) {
    //             suspect.erase(x);
    //         }

    //         if(suspect.size() == 1 and mi == -1) {
    //             mi = shocks;
    //         }
    //     } else if(type == '?') {
    //         if(q == n) {
    //             break;
    //         }
    //         char guess = s[0];

    //         shocks++;

    //         if(suspect.count(guess)) suspect.erase(guess);

    //         if(suspect.size() == 1 and mi == -1) {
    //             mi = shocks;
    //         }
    //     }
    // }

    // if(mi == -1) mi = shocks;

    // cout << shocks-mi << endl;
}