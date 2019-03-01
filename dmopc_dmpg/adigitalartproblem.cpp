// https://dmoj.ca/problem/dmopc18c5p0

#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    float a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    if(s == "Multiply") {
        cout << a*x << " " << y*b << " " << c*z << endl;
    } else if (s == "Screen") {
        cout << 1.0- ((1.0-a)*(1.0-x)) << " " << 1.0-((1.0-b)*(1.0-y)) << " " << 1.0-((1.0-c)*(1.0-z)) << endl;
    } else if (s == "Overlay") {
        if(a < 0.5) {
            cout << 2.0*a*x << " ";
        }
        else {
            cout << 1.0 - (2.0*(1.0-a)*(1.0-x)) << " ";
        }

        if(b < 0.5) {
            cout << 2*b*y << " ";
        }
        else {
            cout << 1.0 - (2.0 * (1.0-b) * (1.0-y) ) << " ";
        }

        if(c < 0.5) {
            cout << 2.0*c*z << endl;
        }
        else {
            cout << 1.0 - (2.0*(1.0-c)*(1.0-z)) << endl;
        }
        
    }
}

