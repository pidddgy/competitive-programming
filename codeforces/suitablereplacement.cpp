// https://codeforces.com/contest/825/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    cin >> a >> b;

    map<char, int> acnt;
    map<char, int> bcnt;
    int q = 0;
    deque<int> qinds;
    int mainicnt = INT_MAX;
    for(int i = 0; i < a.size(); i++) {
        char x = a[i];
        acnt[x]++;
        if(x == '?') {
            q++;
            qinds.emplace_back(i);   
        }
    }

    set<char> bS;
    for(char x: b) {
        bcnt[x]++;
        bS.emplace(x);
        mainicnt = max(mainicnt, bcnt[x]);
    }

    int l = 1;
    int r = 1e8;
    int lastgood = -1;
    while(l <= r) {
        int m = (l+r)/2;
        int need = 0;
        cerr << "trying " << m << endl;
        for(auto &x: bS) {
            int rep = max(0LL, (m*bcnt[x]) - acnt[x]);
            cerr << "need " << rep << " of " << x << endl;
            need += rep;
        }

        if(need <= qinds.size()) {
            lastgood = m;
            l = m+1;
        } else {
            r = m-1;
        }
    }

    // cerr << "can make " << lastgood << endl;

    // if(a.size() > 100) {
    //     cout << qinds.size() << endl;
    //     cout << b << endl;
    //     cout << lastgood << endl;
    // }
    for(char x: bS) {
        int replacing = (lastgood*bcnt[x]) - acnt[x];

        for(int i = 1; i <= replacing; i++) {
            if(qinds.size()) {
                a[qinds.front()] = x;
                qinds.pop_front();
            } else break;
        }
    }

    for(auto &x: a) {
        if(x == '?') x = 'a';
    }


    cout << a << endl;
}