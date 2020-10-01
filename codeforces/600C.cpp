// https://codeforces.com/contest/600/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
#define cerr if(false) cerr

const string alpha = "abcdefghijklmnopqrstuvwxyz";
const string alphaRev = "zyxwvutsrqponmlkjihgfedcba";
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    map<char, int> cnt;
    for(char x: s) {
        cnt[x]++;
    }

    if(cnt.size()==1) {
        cout << s << endl;
        return 0;
    }

    int numOdd = 0;
    for(char x: alpha) {
        numOdd += (cnt[x]%2);
    } 

    int its = 0;
    while(numOdd > 1 and cnt.size()> 1) {
        its++;

        if(its > 1e6) break;
        char small;
        char big;
        for(char x: alpha) {
            if(cnt[x]%2) {
                small = x;
                break;
            }
        }

        for(char x: alphaRev) {
            if(cnt[x]%2) {
                big = x;
                break;
            }
        }

        watch(small)
        watch(big)
        watch(numOdd)
        if(small == big) {
            break;
        }

        cnt[big]--;
        cnt[small]++;
        numOdd -= 2;
    }

    // cout << "HIIIII" << endl;

    deque<char> ans;

    for(char x: alpha) {
        if(cnt[x]%2) {
            ans.emplace_back(x);
            cnt[x]--;
            break;
            // cerr << "using " << x << endl;
            // for(int i = 1; i <= cnt[x]; i++) {
            //     ans.emplace_back(x);
            // }
            // cnt[x] = 0;
            // break;
        }
    }
    
    for(char x: alphaRev) {
        while(cnt[x]) {
            ans.emplace_front(x);
            ans.emplace_back(x);
            cnt[x] -= 2;
        }
    }

    for(char x: ans) {
        cout << x;
    }
    cout << endl;
}