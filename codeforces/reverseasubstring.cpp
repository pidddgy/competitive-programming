// http://codeforces.com/contest/1155/problem/A

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main() {
    int N;
    cin >> N;

    string s;
    cin >> s;
    s = "."+s;

    char prev = s[1];
    for(int i = 2; i <= N; i++) {
        if(s[i] < prev) {
            cout << "YES" << endl;
            cout << i-1 << " " << i << endl;
            return 0;
        }
        prev = s[i];
    }

    cout << "NO" << endl;
}
