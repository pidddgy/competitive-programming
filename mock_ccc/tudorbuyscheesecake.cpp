// https://dmoj.ca/problem/nccc7j4
 
#include <bits/stdc++.h>
using namespace std;

int havea[26];
int haveb[26];
    
int main() {
    string a, b;
    getline(cin, a);
    getline(cin, b);

    int buy = 0;

    for(char chr: a)
        havea[chr-'A']++;

    for(char chr: b)
        haveb[chr-'A']++;

    for(int i = 0; i < 26; i++) {
        int diff = havea[i] - haveb[i];

        // We don't buy negative candles!
        if(diff < 0)
            diff = 0;

        buy += diff;
    }

    cout << buy << endl;
}
