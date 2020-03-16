// https://atcoder.jp/contests/abc143/tasks/abc143_a

#include <bits/stdc++.h>
using namespace std;


int main() {

    int a, b;
    cin >> a >> b;

    cout << max(0, a-(b*2)) << endl;
}