// https://codeforces.com/contest/1085/problem/C

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define watch(x) cerr << (#x) << " is " << (x) << endl;

const int gridsz = 1050;
int main() {
    ios::sync_with_stdio(0);
    cin.sync_with_stdio(0);
    cin.tie(0);

    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    int bestdis = INT_MAX;
    int bestx;
    int besty;
    for(int i = 0; i < gridsz; i++) {
        for(int j = 0; j < gridsz; j++) {
            int totdis = 0;
            totdis += abs(xa-i) + abs(ya-j);
            totdis += abs(xb-i) + abs(yb-j);
            totdis += abs(xc-i) + abs(yc-j);
            totdis++;

            if(totdis < bestdis) {
                bestx = i;
                besty = j;
                bestdis = totdis;
            }
        }
    }

    cout << bestdis << endl;
    cout << bestx << " " << besty << endl;

    int bxcpy = bestx;
    int bycpy = besty;
    for(int scope = 1; scope <= 1; scope++) {
        while(bxcpy != xa or bycpy != ya) {
            if(bxcpy > xa) {
                bxcpy--;
            } else if(bxcpy < xa) {
                bxcpy++;
            } else if(bycpy > ya) {
                bycpy--;
            } else if(bycpy < ya) {
                bycpy++;
            }

            cout << bxcpy << " " << bycpy << endl;
        }
    }

    bxcpy = bestx;
    bycpy = besty;
    for(int scope = 1; scope <= 1; scope++) {
        while(bxcpy != xb or bycpy != yb) {
            if(bxcpy > xb) {
                bxcpy--;
            } else if(bxcpy < xb) {
                bxcpy++;
            } else if(bycpy > yb) {
                bycpy--;
            } else if(bycpy < yb) {
                bycpy++;
            }

            cout << bxcpy << " " << bycpy << endl;
        }
    }

    bxcpy = bestx;
    bycpy = besty;
    for(int scope = 1; scope <= 1; scope++) {
        while(bxcpy != xc or bycpy != yc) {
            if(bxcpy > xc) {
                bxcpy--;
            } else if(bxcpy < xc) {
                bxcpy++;
            } else if(bycpy > yc) {
                bycpy--;
            } else if(bycpy < yc) {
                bycpy++;
            }

            cout << bxcpy << " " << bycpy << endl;
        }
    }
}
