// https://dmoj.ca/problem/dmopc14c2p2

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int N; cin >>  N;
    cin.ignore();
    string aqt;
    getline(cin, aqt);
    vector<int> loglen;

    for(int chr = 0; chr < aqt.size(); chr++) {
        if(aqt[chr] == 'O') {
            if(loglen.empty()) 
                loglen.push_back(0);
            loglen.back()++;
        }
        else if(!loglen.empty())
            if(loglen.back() != 0 && chr != aqt.size() - 1)
                loglen.push_back(0);
    }
    for(int i = 0; i  < loglen.size(); i++) {
        if(loglen[i] == 0)
            loglen.erase(loglen.begin()+i);
    }
    cout << loglen.size() << endl;
    for(auto log: loglen) {
        for(int i = 0; i < log; i++) {
            cout << "O";
        }
        cout << endl;
    }
}
