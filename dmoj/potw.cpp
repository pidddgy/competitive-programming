// link

#include <bits/stdc++.h>
using namespace std;
int main() {
    int a = 100;
    for(int i = 1; i <= 4; i++) {
        a -= 25;
        cout << "gain " << a << endl;
        a *= 2;
    }
}