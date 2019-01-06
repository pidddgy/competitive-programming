// http://codeforces.com/contest/1096/problem/B

#include <bits/stdc++.h>
using namespace std;
int main() {
    int N; string S;
    cin >> N;
    cin.ignore();
    getline(cin, S);
    int count[26]; for(int i = 0; i < 26; i++) count[i] = 0;

    for(int i = 0; i < N; i++) {
        count[S[i]-'a']++;
    }

    int total = 0;

    for(int i = 0; i < 26; i++) {
        for(int j = count[i]; j >= 1; j--) {
            cout << "how many ways are there to have " << j << " of " << S[i] << endl;

            // Find number of adjacent chars that we can remove
            for(int k = 0; k < N; k++) {
                cout << "starting from index " << k << endl;
                int newC[26]; for(int l = 0; l < 26; l++) newC[l] = count[l];

                for(int m = k; m < 26; m++) {
                    if(newC[ S[m]-'a' ] > 0) {
                        bool good = true;
                        newC[ S[m]-'a' ]--;
                        cout << "subtracting from " << S[m] << endl;
                        for(int aa = 0; aa < 26; aa++)
                            if(newC[aa] != 0 && aa != S[i]-'a') good = false;
                        if(good) break;
                    } else break;
                }

                bool found = true;
                for(int l = 0; l < 26; l++)
                    if(newC[l] != 0 && l != S[i]-'a') found = false;
                if(newC[S[i]-'a'] != j) found = false;

                if(found) {
                    total++;
                    cout << "Found a way " << endl;
                }
            }
            cout << endl;
        }
    }
    cout << total+1 << endl;
}