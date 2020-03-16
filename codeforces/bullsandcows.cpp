// https://codeforces.com/problemsets/acmsguru/problem/99999/486

#include <bits/stdc++.h>
using namespace std;
bool aHas[13];
bool bHas[13];
int a[5], b[5];

int bull = 0;
int cow = 0;
int main() {
    for(int i = 1; i <= 4; i++) {
        char cute;
        cin >> cute;

        a[i] = cute-'0';
    }
    for(int i = 1; i <= 4; i++) {
        char cute;
        cin >> cute;

        b[i] = cute-'0';
    }

    for(int i = 1; i <= 4; i++) {
        if(a[i] == b[i]) bull++;
        else {
            aHas[a[i]] = true;
            bHas[b[i]] = true;
        }
    }

    for(int i = 0; i <= 9; i++) {
        if(aHas[i] && bHas[i]) cow++;
    }

    cout << bull << " " << cow << endl;

}