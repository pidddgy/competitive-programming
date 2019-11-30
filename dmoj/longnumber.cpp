#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    string s;
    cin >> s;
    s = "."+s;

    int f[11];
    for(int i = 1; i <= 10; i++) cin >> f[i];

    bool used = false;
    int i = 1;
    for(;i<=N;i++) {
        if(f[s[i]-'0'] > s[i]-'0') {
            used = true;
        }
        if(!used) cout << s[i];
        else if(used && f[s[i]-'0'] < s[i]-'0') {
            break;
        } else {
            cout << f[s[i]-'0'] ;
        }

        
    }

    for(;i<=N;i++) cout << s[i];

    cout << endl;
}
