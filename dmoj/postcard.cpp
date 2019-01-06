// http://codeforces.com/contest/1099/problem/C

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    string aqt;
    getline(cin, aqt);
    int N;
    cin >> N;

    int fc = 0; // flake count (-1, 0, +1)
    int cc = 0; // cane count (-1, 0)
    int nc = 0; // normal chararater (not flake or cane)

    for(auto chr: aqt) {
        if(chr == '*')
            fc++;
        else if(chr == '?')
            cc++;
        else nc++;
    }

    if(nc < N) {
        // if we need more letters, then there needs to be enough at least 1 flake
        int diff = N - nc;

        if(fc == 0) // not enough flakes
            cout << "Impossible"  << endl;
        else
            for(int i = 0; i < aqt.length(); i++) {
                if(aqt[i] == '?') 
                    continue;
                
                if(aqt[i] == '*') {
    
                    while(diff > 0) {
                        cout << aqt[i-1];
                        diff--;
                    }
                } 
                else cout << aqt[i];
            }
            cout << endl;
        }
        
    if(nc > N) {
        // if we need less letters, there needs to be enough flake + cane
        int diff = nc-N;
        if(fc+cc < diff)
            cout << "Impossible"  << endl;
        
        else {
            for(int i = 0; i < aqt.length(); i++) {
                if((aqt[i+1] == '*' || aqt[i+1] == '?') && diff > 0) {
                    diff--;
                    continue;
                }

                if(aqt[i] == '*' || aqt[i] == '?')
                    continue;

                cout << aqt[i];
            }
            cout << endl;
        }
    }

    if(nc == N) {
        for(auto chr: aqt) {
            if(chr != '*' && chr != '?')
                cout << chr;
        }
        cout << endl;
    }

}