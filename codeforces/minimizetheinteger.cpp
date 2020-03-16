// https://codeforces.com/problemset/problem/1251/C

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int T;
    cin >> T;
    
    while(T--) {
        string s;
        cin >> s;

        queue<string> Q;
        map<string, bool> vis;

        Q.push(s);
        // cout << "pushing " << s << endl;
        vis[s] = true;

        string ans = s;
        while(!Q.empty()) {
            string S = Q.front(); Q.pop();

            // watch(S)
            ans = min(ans, S);
            for(int i = 1; i < s.size(); i++) {
                // cout << "currently on " << i << endl;
                // cout << S[i]-'0' << endl;
                // cout << S[i-1]-'0' << endl;
                

                if((S[i]-'0')%2 != (S[i-1]-'0')%2) {
                    string n = S;
                    swap(n[i], n[i-1]);
                    if(!vis[n]) {
                        Q.push(n);
                        // cout << "pushing " << n << endl;
                        vis[n] = true;
                    }
                }
            }
            // cout << endl;
        }

        cout << ans << endl;
    }



}