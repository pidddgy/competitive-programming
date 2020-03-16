// https://atcoder.jp/contests/abc126/tasks/abc126_b

#include <bits/stdc++.h>
using namespace std;
bool val(int n) {
    return (1 <= n && n <= 12);
}
int main() {
    string a, b;
    for(int i = 0; i < 2; i++) {
        char c;
        cin >> c;
        a += c;
    }

    for(int i = 0; i < 2; i++) {
        char c;
        cin >> c;
        b += c;
    }

    if(val(stoi(a)) && val(stoi(b)))
        cout << "AMBIGUOUS" << endl;
    else if(val(stoi(a)))
        cout << "MMYY" << endl;
    else if(val(stoi(b)))
        cout << "YYMM" << endl;
    else
        cout << "NA" << endl;
}