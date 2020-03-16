// https://codeforces.com/contest/1303/problem/A

#include <bits/stdc++.h>
#define cerr if(false) cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int T;
    cin >> T;

    while(T--) {
        string s;
        cin >> s;

        int f = -1;
        int l = -1;

        for(int i = 0; i < s.size(); i++) {
            if(f == -1 and s[i] == '1') {
                f = i;
            }

            if(s[i] == '1') {
                l = i;
            }
        }

        int e = 0;
        
        watch(f)
        watch(l)
        if(f != -1)
        if(l != -1)
        for(int i = f; i <= l; i++) {
            if(s[i] == '0') {
                e++;
            }
        }

        cout << e << endl;
    }
}