// https://dmoj.ca/problem/dmopc18c5p4

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N; cin >> N;
    cin.ignore();
    string a, b;

    getline(cin, a);
    getline(cin, b);

    a = "." + a;
    b = "." + b;

    int nOddA = 0;
    int nEvenA = 0;

    int nOddB = 0;
    int nEvenB = 0;
    
    for(int i = 1; i <= N; i++) {
        if(a[i] == 'F') {
            if(i % 2 == 0)
                nEvenA++;
            else
                nOddA++;
        }

        if(b[i] == 'F') {
            if(i % 2 == 0)
                nEvenB++;
            else
                nOddB++;
        }
    }


    if(nOddA - nEvenA == nOddB - nEvenB) cout << "YES" << endl;
    else cout << "NO" << endl;
}
