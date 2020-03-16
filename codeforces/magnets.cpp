// http://codeforces.com/contest/344/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    int r = s[1];
    int res = 1;
    for(int i = 0; i < N-1; i++){
        cin >> s;
        if(s[0] == r) {
            res++;
        }
        r = s[1];

        
    }
    cout << res << endl;
}
