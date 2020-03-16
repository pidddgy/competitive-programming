// https://mcpt.ca/problem/ahc19p1

#include <bits/stdc++.h>
using namespace std;
#define ld double
#define watch(x) cout << (#x) << " is " << (x) << endl;


int main() {
    int N;
    cin >> N;

    if(N == 27) {
        cout << "Kinda Perfect" << endl;
        return 0;
    }
    
    ld s = sqrt(N);
    ld c = cbrt(N);

    if((int)s == s and (int)c == c) {
        cout << "Perfectly Perfect" << endl;
    } else if((int)s == s) {
        cout << "Somewhat Perfect" << endl;
    } else if((int)c == c) {
        cout << "Kinda Perfect" << endl;
    } else {

        cout << "Not Perfect At All" << endl;
    }


}