// https://dmoj.ca/problem/vpex1p1

#include <bits/stdc++.h>
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {

    int mi = INT_MAX;
    int s1 = 0;
    for(int i = 0; i < 5; i++) {
        int a;
        cin >> a;

        mi = min(mi, a);
        s1 += a;
    }

    s1 -= mi;

    mi = INT_MAX;
    int s2 = 0;

    for(int i = 0; i < 5; i++) {
        int a;
        cin >> a;

        mi = min(mi, a);
        s2 += a;
    }

    s2 -= mi;

    cout << max(s1, s2) << endl;

}