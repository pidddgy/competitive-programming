// https://dmoj.ca/problem/year2019p1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int w1, h1, w2, h2;
    cin >> h1 >> w1 >> h2 >> w2;
    int a = 0;
    int b = 0;

    for(int i = 1; i < 1000; i++) {
        if(i % w1 == 0 || i == 1) {
            b++;
        }
        if(i % w2 == 0 || i == 1) {
            a++;
        } 

        if(a == h1 && b == h2) {
            cout << -1 << endl;
            break;
        }
        else if(b == h2) {
            cout << 1 << endl;
            break;
        }
        else if(a == h1) {
            cout << 2 << endl;
            break;
        }
    }
}