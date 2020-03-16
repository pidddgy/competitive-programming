// http://codeforces.com/contest/1146/problem/0

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    int acnt = 0;
    for(auto x: s) if(x == 'a') acnt++;

    while(acnt*2 <= s.size()) {
        s.pop_back();
    }

    cout << s.size() << endl;
}

