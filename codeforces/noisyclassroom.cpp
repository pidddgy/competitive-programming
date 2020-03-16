// http://codeforces.com/contest/1166/problem/A

#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> a;
unordered_map<char, int> b;

int main() {

    int N;
    cin >> N;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;

        if(a[s[0]] < b[s[0]]) {
            a[s[0]]++;
        } else {
            b[s[0]]++;
        }
    }
    

    int ans = 0;
    string abc = "abcdefghijklmnopqrstuvwxyz";
    for(char chr: abc) {
        ans += a[chr] * (a[chr]-1)/2;
        ans += b[chr] * (b[chr]-1)/2;
    }

    cout << ans << endl;

}
