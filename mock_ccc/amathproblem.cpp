// https://dmoj.ca/problem/nccc1j3s1    

#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    double K, P, X ; cin >> K >> P >> X;
    double aqt = 2147483647; double M = 0;
    for(;;) {
        M++;
        if((M*X) + ( (K*P)/M ) > aqt) {
            cout << fixed << setprecision(3) << aqt << endl;
            return 0;
        }
        aqt = (M*X) + ( (K*P )/M);
        
    }
}
