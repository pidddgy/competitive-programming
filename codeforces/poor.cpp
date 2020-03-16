// https://atcoder.jp/contests/abc155/tasks/abc155_a

#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;

    set<int> s;
    s.emplace(a);
    s.emplace(b);
    s.emplace(c);

    if(s.size() == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}