// https://dmoj.ca/problem/ccc11j3

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int aqt, bqt, ret, newNum;
    cin >> aqt >> bqt;

    for(;;) {
        newNum = aqt - bqt;
        aqt = bqt;
        if(newNum > aqt) 
            break;
        bqt = newNum;
        ret++;
    }
    cout << ret+3 << endl;
}   
