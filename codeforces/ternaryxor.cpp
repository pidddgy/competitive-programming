// https://codeforces.com/contest/1328/problem/C

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;

    while(t--) {
        int N;
        cin >> N;

        string s;
        cin >> s;

        string a, b;

        bool saw1 = false;
        for(char x: s) {
            if(x == '2') {
                if(!saw1) {
                    a += "1";
                    b += "1";
                } else {
                    a += "0";
                    b += "2";
                }
            } else if(x == '0') {
                a += "0";
                b += "0";
            } else if(x == '1') {
                if(!saw1) {
                    a += "1";
                    b += "0";
                    saw1 = true;
                } else {
                    a += "0";
                    b += "1";
                }
            }
        }

        cout << a << endl << b << endl;
    }
}