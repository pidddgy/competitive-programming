#include <bits/stdc++.h>
using namespace std;

string type(char cute) {
    cute = tolower(cute);
    if(cute == 'a' or cute == 'e' or cute == 'i' or cute == 'o' or cute == 'u') {
        return "vowel";
    } else {
        return "consonant";
    }
}
int main() {
    int N;
    cin >> N;

    string s;
    cin >> s;

    string cur = type(s[0]);
    int consec = 1;
    int ans = 0;
    for(int i = 1; i < N; i++) {
        if(type(s[i]) == cur and consec == 3) {
            consec = 1;
            cur = type(s[i]);
            ans++;
        } else if(type(s[i]) == cur) {
            consec++;
        } else {
            cur = type(s[i]);
            consec = 1;
        }

    }

    cout << ans << endl;

    
}