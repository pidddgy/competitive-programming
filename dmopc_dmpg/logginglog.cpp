// https://dmoj.ca/problem/dmopc14c2p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int D; cin >> D;
    for(int aqt = 0; aqt < D; aqt++) {
        int T; cin >> T;
        int total = 0;
        for(int i = 0; i < T; i++) {
            int bqt; cin >> bqt;
            total += bqt;
        }
        if(total == 0) 
            cout << "Weekend" << endl;
        else
            cout << "Day " << aqt+1 << ": " << total << endl;
    }
}
