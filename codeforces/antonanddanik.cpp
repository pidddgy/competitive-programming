// http://codeforces.com/contest/734/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    int a = 0;
    int d = 0;
    for(auto chr: s) {
        if(chr == 'A') a++;
        else d++;       
    }

    if(a > d) cout << "Anton" << endl;
    else if(d > a) cout << "Danik" << endl;
    else cout << "Friendship" << endl;
}
