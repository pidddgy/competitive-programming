// https://dmoj.ca/problem/dmopc19c4p0

#include <bits/stdc++.h>
using namespace std;
int main() {
    string cute;
    string cutee;

    cin >> cute >> cutee;

    int diff = 0;
    for(int i = 0; i < cute.size(); i++) {
        if(cute[i] != cutee[i]) {
            diff++;
        }
    }

    if(diff == 1) {
        cout << "LARRY IS SAVED!" << endl;
    } else {
        cout << "LARRY IS DEAD!" << endl;
    }
}