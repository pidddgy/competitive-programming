// https://dmoj.ca/problem/dmpg19b2

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

int main() {
    int a[4];
    for(int i = 0; i < 4; i++) {
        int c;
        cin >> c;
 
        a[i] = c;
    }

    int l = 0;
    int li = 0;
    for(int i = 0; i < 4; i++) {
        if(a[i] > l) {
            li = i;
            l = a[i];
        }
    }

    a[li] = 0;

    int sl = 0;
    int sli = 0;
    for(int i = 0; i < 4; i++) {
        if(a[i] > sl) {
            sli = i;
            sl = a[i];
        }
    }

    if(abs(sli - li) == 2) {
        cout << "trans" << endl;
    } else cout << "cis" << endl;

}