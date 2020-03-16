// https://mcpt.ca/problem/ahc19p2

#include <bits/stdc++.h>
using namespace std;
int main() {
    string C, E;
    cin >> C >> E;

    string alp = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";


    for(int i = 0; i < C.size(); i += 2) {
        string a;
        a += C[i];
        a += C[i+1];

        string b;
        b += E[i];
        b += E[i+1];

        int aa = stoi(a);
        int bb = stoi(b);

        cout << alp[abs(aa-bb)];
    }

    cout << endl;
}