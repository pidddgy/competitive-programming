// https://dmoj.ca/problem/nccc7j5


#include <bits/stdc++.h>
using namespace std;
const int maxC = 210000000;
bool dp[maxC];

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int t = 0;
    for(int i = a; i <= b; i++) {
        for(int j = i; j <= d; j++) {
            if(dp[(i*123)+j] != 0) {
                if(dp[i*123+j] == 1)
                    t++;
            }

            int aa = gcd(i, j);
            if(gcd(i, j) == 1) {
                t++;
            }

            dp[i*123+j] = aa;
        }
    }

    cout << t << endl;
}