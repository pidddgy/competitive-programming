// https://codeforces.com/contest/1144/problem/A

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
char next(char n) {
    if(n == 'z') return 'a';
    else return(n+1);
}
int main() {
    int N;
    cin >> N;


    while(N--) {
        string s;
        cin >> s;

        bool diverse = true;
        sort(s.begin(), s.end());
        cout << s << endl;
        for(int i = 1; i < s.size()-1; i++) {
            cout << "i is " << i << endl;
            watch(s[i+1])
            watch(next(s[i]))
            if(s[i+1] != next(s[i])) {
                diverse = false;
            }
        }

        

        if(diverse) cout << "yes" << endl;
        else cout << "no" << endl;
        cout << endl;
    }
}