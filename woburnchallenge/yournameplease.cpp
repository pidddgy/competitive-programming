// http://wcipeg.com/problem/wc184i2

#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl;
using namespace std;
int main() {
    int N, K;
    cin >> N >> K;

    char cur = 'A';
    string s;

    while(K > 5) {
        char temp = ((cur-65+2) % 26) + 65;
        s = s+temp;

        temp = ((cur-65+1) % 26) + 65;
        s = s+temp;

        K -= 5;
    }

    while(K > 0) {
        K--;
        s = s+cur;
    }

    cout << s << endl;



}
