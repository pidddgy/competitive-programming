// https://dmoj.ca/problem/ccc03s1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int curr = 1;
    for(;;) {
        int aqt; cin >> aqt;
        if(aqt == 0) {
            cout << "You Quit!" << endl;
            return 0;
        }
        if(!(curr+aqt > 100))
            curr += aqt;

        if(curr == 54) curr = 19;
        if(curr == 90) curr = 48;
        if(curr == 99) curr = 77;
        if(curr == 9) curr = 34;
        if(curr == 40) curr = 64;
        if(curr == 67) curr = 86;

        cout << "You are now on square " << curr << endl;
        if(curr == 100) {
            cout << "You Win!" << endl;
            return 0;
        }
    }
}
