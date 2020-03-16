// https://codeforces.com/contest/1216/problem/A

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    s = "."+s;

    int ans = 0;
    for(int i = 0; i < N/2; i++) {
        int l = i*2+1;
        int r = i*2+2;

        if(s[l] == s[r]) {
            if(s[l] == 'a') {
                s[r] = 'b';
            } else {
                s[r] = 'a';
            }

            ans++;
        }
    }


    cout << ans << endl;

    for(int i = 1; i <= N; i++) {
        cout << s[i];
    }
    cout<<endl;

}