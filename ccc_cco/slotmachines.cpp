// https://dmoj.ca/problem/ccc00j3

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int Q, aqt, bqt, cqt; int ret = 0;
    cin >> Q >> aqt >> bqt >> cqt;

    int MQT = 1;
    while(Q != 0) {
        Q--;
        if(MQT == 1) {
            aqt++;
            if(aqt == 35) {
                Q += 30;
                aqt = 0;
            }
        }

        if(MQT == 2) {
            bqt++;
            if(bqt == 100) {
                Q += 60;
                bqt = 0;
            }
        }

        if(MQT == 3) {
            cqt++;
            if(cqt == 10) {
                Q += 9;
                cqt = 0;
            }
        }

        if(MQT == 3) 
            MQT = 1;
        else
            MQT++;
        ret++;
    }
    cout << "Martha plays " << ret << " times before going broke." << endl;
}
