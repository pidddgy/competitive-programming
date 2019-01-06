// https://dmoj.ca/problem/ccc09s1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int aqt, bqt, rqt = 0;
    cin >> aqt >> bqt;

    for(int i = 0; i < 23; i++) {
        if(pow(i, 6) >= aqt && pow(i, 6) <= bqt)
            rqt++;
    }

    cout << rqt << endl;
}

