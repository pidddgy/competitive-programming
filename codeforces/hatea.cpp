// http://codeforces.com/contest/1146/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int N = s.size();
    
    deque<char> fir;
    deque<char> sec;
    for(auto x: s) sec.push_back(x);
    for(int i = 0; i < N; i++) {
        if(sec.front() != 'a')
            fir.push_back(sec.front());
        
        sec.pop_front();

        if(fir == sec) {
            cout << s.substr(0, i+1) << "\n";
            return 0;
        }
    }

    cout << ":(" << "\n";
}

