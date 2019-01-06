// http://codeforces.com/contest/1095/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    vector<int> aqt;
    cin >> N;
    cin.ignore();
    for(int i = 0; i < N; i++) {
        int cute;
        cin >> cute;
        aqt.push_back(cute);
    }

    int smallest = 2147483647;

    sort(aqt.begin(), aqt.end());

    // remove biggest value
    int maxA = -2147483647;
    int minA = 2147483647;
    for(int i = 0; i < aqt.size() - 1; i++) {
        if(aqt[i] > maxA) maxA = aqt[i];
        if(aqt[i] < minA) minA = aqt[i];
    };
    
    if(maxA - minA < smallest) 
        smallest = maxA - minA;

    int maxB = -2147483647;
    int minB = 2147483647;
    // remove smalllest vaue

    for(int i = 1; i < aqt.size(); i++) {
        if(aqt[i] > maxB) maxB= aqt[i];
        if(aqt[i] < minB) minB = aqt[i];
    }
    if(maxB - minB < smallest) 
        smallest = maxB - minB;
    cout << smallest << endl;
}
