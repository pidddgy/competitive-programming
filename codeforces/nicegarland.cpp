// http://codeforces.com/contest/1108/problem/C

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    vector<string> pats = {"RGB", "RBG", "GRB", "GBR", "BRG", "BGR"};
    int N;
    cin >> N;
    string s;
    cin >> s;

    int ans = numeric_limits<int>::max();
    string cute;
    for(string pat: pats) {
        int edit = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != pat[i%3]) {
                edit++;
            }
        }

        if(edit < ans) {
            ans = min(ans, edit);
            cute = pat;
        }
    }
    
    cout << ans << endl;
    for(int i = 0; i < N; i++) {
        cout << cute[i%3];
    }
    cout << endl;
}
