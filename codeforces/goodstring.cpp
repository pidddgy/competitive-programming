// http://codeforces.com/contest/1165/problem/C

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    S = "."+S;
    string out;

    int prev = 1;
    int cur;
    for(int cur = 2; cur <= N; cur++) {
        if(S[cur] != S[prev]) {
            out += S[prev];
            out += S[cur];
            prev = cur+1;
            cur++;
        }
    }
    cout << S.size()-1-out.size() << endl;
    cout << out << endl;
}
