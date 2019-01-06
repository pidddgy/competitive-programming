/*
ID: marcus.7
PROG: ride
LANG: C++                 
*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream cin("ride.in");
    ofstream cout("ride.out");

    string aqt, bqt;
    getline(cin, aqt);
    getline(cin, bqt);

    int a = 1;
    int b = 1;

    for(int i = 0; i < aqt.size(); i++)
        a *= aqt[i]-'A'+1;

    for(int i = 0; i < bqt.size(); i++)
        b *= bqt[i]-'A'+1;

    if(a % 47 == b % 47) 
        cout << "GO" << endl;
    else
        cout << "STAY" << endl;
    
    return 0;
}