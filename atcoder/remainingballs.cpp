// https://atcoder.jp/contests/abc154/tasks/abc154_a

#include <bits/stdc++.h>
using namespace std;
int main() {
    string S, T;
    int A, B;
    cin >> S >> T;
    cin >> A >> B;

    string U;
    cin >> U;

    if(U == T) B--;
    else A--;

    cout << A << " " << B << endl;
}