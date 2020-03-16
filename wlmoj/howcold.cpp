#include <bits/stdc++.h>
#define ld long double
using namespace std;

int main() {

    ld a[4]; 
    cin >> a[0] >> a[1] >> a[2];

    // convert all values to fahrenheit in end
    vector<string> poss = {
        "000",
        "001",
        "010",
        "011",
        "100",
        "101",
        "110",
        "111"
    };

    for(string x: poss) {
        // 1 = some ind was in fahrenheit
        for(int i = 0; i < 3; i++) {
            ld b[4];
            if(x[i] == '1') {
                b[i] = (a[i]*1.8) + 32;
            } else {
                b[i] = a[i];
            }

            if(b[0] < b[1] and b[1] < b[2]) {
                // cout << b[1] << endl;
                // cout << b[2] << endl;
                // cout << x << endl;
                cout << "Possible" << endl;
                return 0;
            }
        }
    }   

    cout << "Impossible" << endl;
}