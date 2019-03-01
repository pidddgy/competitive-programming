// http://wcipeg.com/problem/wc183i1

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N-1; i++) {
        cout << "#";
    }
    cout << "." << endl;
    for(int i = 0; i < N-2; i++) {
        cout << "#";
        for(int j = 0; j < N-2; j++) {
            cout << ".";
        }
        cout << "#" << endl;
    }
    for(int i = 0; i < N-1; i++) {
        cout << "#";
    }
    cout << "." << endl;
    for(int i = 0; i < N-1; i++) {
        cout << "#";
        for(int j = 0; j < i; j++) {
            cout << ".";
        }
        cout << "#";
        for(int j = 0; j < N-i-2; j++) {
            cout << ".";
        }
        cout << endl;
    }
}
