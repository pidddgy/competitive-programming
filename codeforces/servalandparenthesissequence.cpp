// https://codeforces.com/contest/1153/problem/C

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
#define endl '\n'
signed main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    string s;
    cin >> s;

    s = "."+s;

    int ocnt = 0;

    for(int i = 1; i <= N; i++) {
        if(s[i] == '(') ocnt++;
    }

    for(int i = 1; i <= N; i++) {
        if(s[i] == '?') {
            if(ocnt < N/2) {
                s[i] = '(';
                ocnt++;
            } else {
                s[i] = ')';
            }
        }
    }

    stack<int> S;
    for(int i = 1; i <= N; i++) {
        if(s[i] == '(') {
            S.push(s[i]);
        } else if(s[i] == ')') {
            if(S.empty()) {
                cout << ":(" << endl;
                return 0;
            }
            if(S.top() == '(') {
                S.pop();
            } else {
                S.push(s[i]);
            }
        }
        if(S.empty() and i != N) {
            cout << ":(" << endl;
            return 0;
        }
    }

    if(S.empty()) {
        for(int i = 1; i <= N; i++) {
            cout << s[i];
        }
        cout << endl;
    } else {
        cout << ":(" << endl;
    }
}