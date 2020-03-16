// http://codeforces.com/contest/1155/problem/B

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N;
    cin >> N;

    queue<int> next8;
    queue<int> not8;
    for(int i = 1; i <= N; i++) {
        char a;
        cin >> a;
        if(a == '8') {
            next8.push(i);
        } else {
            not8.push(i);
        }
    }
    
    char turn = 'V';
    while(next8.size() + not8.size() > 11) {
        if(turn == 'V') {
            if(not8.size()) {
                not8.pop();
            }
            else {
                next8.pop();
            }
            turn = 'P';
        } else {
            if(next8.size()){
                next8.pop();
            }
            else{
                cout << "NO" << endl;
                return 0;
            }
            turn = 'V';
        }
    }
    
    if(next8.size() == 0) {
        cout << "NO" << endl;
    } else if(not8.size() == 0) {
        cout << "YES" << endl;
    } else if(next8.front() < not8.front()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

