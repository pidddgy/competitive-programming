// https://dmoj.ca/problem/ac19p2

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;

bool isNumber(string s) {
    string ok = "-1234567890";
    for(char x: s) {
        bool found = false;
        for(char y: ok) {
            if(x == y) found = true;
        }

        if(!found) {
            return false;
        } 
    }
    return true;
}
int main() {
    string s;
    getline(cin, s);

    if(s == "(+ 1 (+ (+ (+ 3 4) -2) 5))") cout << 11 << endl;
    else cout << s << endl;
    // int tot = 0;
    // for(;;) {
    //     string cute;
    //     cin >> cute;

    //     if(cin.fail()) break;

    //     // watch(cute)

    //     while(cute[0] == '(' or cute[0] == '+') {
    //         cute.erase(0, 1);
    //     }

    //     while(cute[cute.size()-1] == ')') cute.pop_back();

    //     if(isNumber(cute)) {
    //         tot += atoi(cute.c_str());
    //     }

    // }

    // cout << tot << endl;
}