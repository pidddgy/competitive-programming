// link

#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;

    int x = a;
    int y = b;

    while(x != y) {
        if(x > y) {
            x = x-y;
        }

        if(x < y) {
            y = y-x;
        }
    }

    cout << x << endl;

}