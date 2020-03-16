// https://dmoj.ca/problem/dmopc19c5p0

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, C;
    cin >> N >> C;

    for(int i = 1; i <= N; i++) {
        string s;
        cin >> s;

        int sc;
        cin >> sc;

        if(sc > C) {
            cout << s << " will advance" << endl;
        } else {
            cout << s << " will not advance" << endl;
        }
    }
}