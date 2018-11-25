#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    scanf("%i", &t);
    for(int num = 0; num < t; num++) {
        string s;
        cin >> s;
        
        s.erase(remove(s.begin(), s.end(), '-'));
        
        cout << s.substr(0,2) << "-";
        cout << s.substr(3,5) << "-";
        cout << s.substr(6,9) << endl;
        cout << s << endl;
    } 
}