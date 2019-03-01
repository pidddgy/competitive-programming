#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        string s;
        cin >> s;

        char prev = s[0];
        int l = 1;

        for(int i = 1; i < s.size(); i++) {
            if(s[i] == prev) {
                l++;
            } else {
                cout << l << " " << prev << " ";
                prev = s[i];
                l = 1;
            }
        }

        cout << l << " " << prev << " " << endl;
    }

}